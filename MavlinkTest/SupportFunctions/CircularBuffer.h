//
// Created by fabian on 07.12.23.
//

#ifndef AUTONOMOUS_SOARING_CIRCULARBUFFER_H
#define AUTONOMOUS_SOARING_CIRCULARBUFFER_H

#include <iostream>
#include <vector>
#include <algorithm>


/*
 * Storing data in a buffer of consistent size
 * The buffer is circular, meaning that if the buffer is full and a new element is inserted, the oldest element is removed
 * The buffer is implemented as a vector of type T with a maximum size of maxSize
*/



template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t maxSize;

public:
    CircularBuffer(size_t size) : maxSize(size) {
        buffer.reserve(maxSize);
    }
/**
 * Inserting data into the buffer
 *
 * Inserting data into the buffer. If the buffer is full the oldest element is removed.
 *
 * @param data The data to insert
 */
void insert(const T& data) {
    if (buffer.size() < maxSize) {
        buffer.push_back(data);
    } else {
        buffer.erase(buffer.begin());
        buffer.push_back(data);
    }
}

/**
 * Calculating the average of the buffer
 *
 * Calculating the average of the buffer. If the buffer is empty the function returns 0.0
 *
 * @return The average of the buffer
 */

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

/**
 * Getting the latest element of the buffer
 *
 * Getting the latest element of the buffer. If the buffer is empty the function returns a default constructed object of type T
 *
 * @return The latest element of the buffer
 */
T getLatest() {
    if (buffer.empty()==false){
        return buffer.back();
    }else{
        // maybe trowh an exeption here
        return T();
    }
}

size_t getBufferSize(){
    return buffer.size();
}

bool isEmpty(){
    return buffer.empty();
}

size_t getMaxSize(){
    return maxSize;
}

};




#endif //AUTONOMOUS_SOARING_CIRCULARBUFFER_H
