// Copyright (c) FRC Team 3512, Spartatroniks 2012-2017. All Rights Reserved.

#pragma once

#include <vector>

#include <QtEndian>

template <class T>
bool packetToVar(const std::vector<char>& data, size_t& pos, T& dest) {
    if (pos + sizeof(T) <= data.size()) {
        dest = qFromBigEndian<T>(reinterpret_cast<const uint8_t*>(&data[pos]));
        pos += sizeof(dest);

        return true;
    } else {
        return false;
    }
}
