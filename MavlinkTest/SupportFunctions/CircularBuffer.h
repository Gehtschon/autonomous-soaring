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

public:
    CircularBuffer(size_t size) : maxSize(size) {
        buffer.reserve(maxSize);
    }

    void insert(const T& data) {
        if (buffer.size() < maxSize) {
            buffer.push_back(data);
        } else {
            buffer.erase(buffer.begin());
            buffer.push_back(data);
        }
    }

    double calculateAverage() const {
        double sum = 0.0;
        for (const auto& value : buffer) {
            sum += value;
        }
        return buffer.empty() ? 0.0 : sum / buffer.size();
    }

    void displayBuffer() const {
        for (const auto& value : buffer) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    T getIndex(size_t index) {
        return buffer[index];
    }

    T getLatest() {
        if (buffer.empty()==false){
            return buffer.back();
        }else{
            // maybe trowh an exeption here
            return T();
        }
    }

    bool isEmpty(){
        return buffer.empty();
    }
};


#endif //AUTONOMOUS_SOARING_CIRCULARBUFFER_H
