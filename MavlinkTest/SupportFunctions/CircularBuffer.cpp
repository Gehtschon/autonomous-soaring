//
// Created by fabian on 07.12.23.
//

#include "CircularBuffer.h"
template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size) : maxSize(size), currentIndex(0) {
    buffer.reserve(maxSize);
}

template <typename T>
void CircularBuffer<T>::insert(const T& data) {
    if (buffer.size() < maxSize) {
        buffer.push_back(data);
    } else {
        buffer[currentIndex] = data;
    }

    currentIndex = (currentIndex + 1) % maxSize;

    // Sort the buffer from oldest to newest
    std::sort(buffer.begin(), buffer.end());
}

template <typename T>
double CircularBuffer<T>::calculateAverage() const {
    double sum = 0.0;

    for (const auto& value : buffer) {
        sum += value;
    }

    return buffer.empty() ? 0.0 : sum / buffer.size();
}

template <typename T>
void CircularBuffer<T>::displayBuffer() const {
    for (const auto& value : buffer) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}