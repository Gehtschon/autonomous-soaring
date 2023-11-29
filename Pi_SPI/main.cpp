#include <iostream>
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iomanip>  // Add this line for setw

#define num_bytes 34
const u_int16_t CRC_POLY = 0xC599;
int spi_fd;

void transfer(unsigned char* tx_buffer, unsigned char* rx_buffer, int length) {
    struct spi_ioc_transfer transfer{};
    transfer.tx_buf = (unsigned long)tx_buffer;
    transfer.rx_buf = (unsigned long)rx_buffer;
    transfer.len = length;

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer);
}


// Function to calculate CRC
u_int16_t calculateCRC(const unsigned char* data, int length) {
    u_int16_t crc = 0xFFFF;

    for (int i = 0; i < length; ++i) {
        crc ^= (static_cast<u_int16_t>(data[i]) << 8);

        for (int j = 0; j < 8; ++j) {
            if ((crc & 0x8000) != 0) {
                crc = (crc << 1) ^ CRC_POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
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

// Display received data in decimal format
    std::cout << "Received (Decimal): ";
    for (int i = 0; i < num_bytes; ++i) {
        std::cout << static_cast<int>(rx_buffer[i]) << " ";
    }
    std::cout << std::endl;

    // Display received data in 16-bit hexadecimal half-words
    std::cout << "Received (Hex 16-bit Half-Words): ";
    for (int i = 0; i < num_bytes; i += 2) {
        u_int16_t value = (rx_buffer[i] << 8) | rx_buffer[i + 1];
        std::cout << std::hex << std::setw(4) << std::setfill('0') << value << " ";
    }
    std::cout << std::endl;


    std::cout << "Received (Hex Bytes): ";
    for (int i = 0; i < num_bytes; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(rx_buffer[i]) << " ";
    }
    std::cout << std::endl;


    // Calculate CRC excluding the last two bytes
    u_int16_t calculatedCRC = calculateCRC(rx_buffer, num_bytes - 2);

    // Extract the CRC from the last two bytes (little-endian)
    u_int16_t receivedCRC = static_cast<u_int16_t>(rx_buffer[num_bytes - 2]) |
                           (static_cast<u_int16_t>(rx_buffer[num_bytes - 1]) << 8);


    // Display calculated CRC in hexadecimal format
    std::cout << "Calculated CRC (Hex): " << std::hex << std::setw(4) << std::setfill('0') << calculatedCRC << std::endl;

    // Display received CRC in hexadecimal format
    std::cout << "Received CRC (Hex): " << std::hex << std::setw(4) << std::setfill('0') << receivedCRC << std::endl;

    if (calculatedCRC == receivedCRC) {
        std::cout << "CRC OK" << std::endl;
    } else {
        std::cout << "CRC Mismatch" << std::endl;
    }

    // Close SPI device
    close(spi_fd);

    return 0;
}
