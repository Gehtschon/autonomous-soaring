//
// Created by fabian on 07.12.23.
//

#ifndef AUTONOMOUS_SOARING_CIRCULARBUFFER_H
#define AUTONOMOUS_SOARING_CIRCULARBUFFER_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t maxSize;
    size_t currentIndex;

public:
    CircularBuffer(size_t size);

    void insert(const T& data);

    double calculateAverage() const;

    void displayBuffer() const;
};


#endif //AUTONOMOUS_SOARING_CIRCULARBUFFER_H
