//
// Created by fabian on 30.11.23.
//

#ifndef AUTONOMOUS_SOARING_ROLLINGBUFFER_H
#define AUTONOMOUS_SOARING_ROLLINGBUFFER_H

#include <iostream>
#include <array>

template <typename T, size_t MaxSize>
class RollingBuffer {
public:
    void addData(const T& data);
    const std::array<T, MaxSize>& getBuffer() const;

private:
    std::array<T, MaxSize> buffer;
    size_t currentIndex = 0;
};


#endif //AUTONOMOUS_SOARING_ROLLINGBUFFER_H
