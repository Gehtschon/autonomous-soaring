#include <iostream>
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define num_bytes 34

int spi_fd;

void transfer(unsigned char* tx_buffer, unsigned char* rx_buffer, int length) {
    struct spi_ioc_transfer transfer{};
    transfer.tx_buf = (unsigned long)tx_buffer;
    transfer.rx_buf = (unsigned long)rx_buffer;
    transfer.len = length;

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer);
}

int main() {
    // Open SPI device
    spi_fd = open("/dev/spidev0.0", O_RDWR);
    if (spi_fd < 0) {
        perror("Error opening SPI device");
        return -1;
    }

    // Set SPI mode and bits per word
    int mode = SPI_MODE_0;
    int bits = 8;
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0) {
        perror("Error setting SPI mode or bits per word");
        close(spi_fd);
        return -1;
    }

    // Set SPI speed (Hz)
    int speed = 1000000; // 1 MHz
    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("Error setting SPI speed");
        close(spi_fd);
        return -1;
    }

    // Your SPI communication logic goes here
    // Example: Reading 272 bits from the SPI device
   // const int num_bits = 272;
   // const int num_bytes = (num_bits + 7) / 8; // Round up to the nearest byte
    unsigned char rx_buffer[num_bytes] = {0};

    transfer(nullptr, rx_buffer, num_bytes);

    // Display received data
    std::cout << "Received: ";
    for (int i = 0; i < num_bytes; ++i) {
        std::cout << static_cast<int>(rx_buffer[i]) << " ";
    }
    std::cout << std::endl;

    // Close SPI device
    close(spi_fd);

    return 0;
}
