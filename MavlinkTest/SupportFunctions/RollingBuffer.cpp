//
// Created by fabian on 30.11.23.
//

#include "RollingBuffer.h"
template <typename T, size_t MaxSize>
void RollingBuffer<T, MaxSize>::addData(const T& data) {
    buffer[currentIndex] = data;
    currentIndex = (currentIndex + 1) % MaxSize;
}

template <typename T, size_t MaxSize>
const std::array<T, MaxSize>& RollingBuffer<T, MaxSize>::getBuffer() const {
    return buffer;
}