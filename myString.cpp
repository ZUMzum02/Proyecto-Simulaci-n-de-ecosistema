#include "myString.h"

int myString::calculateLength(const char* str) const {
    int len = 0;
    while (str && str[len] != '\0') {
        ++len;
    }
    return len;
}

void myString::copyString(char* dest, const char* src) const {
    int i = 0;
    while (src && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

myString::myString(const char* str) {
    if (str) {
        size = calculateLength(str);
        data = new char[size + 1];
        copyString(data, str);
    } else {
        size = 0;
        data = nullptr;
    }
}

myString::myString() : size(0), data(nullptr) {}

myString::myString(const myString& other) {
    size = other.size;
    if (size > 0) {
        data = new char[size + 1];
        copyString(data, other.data);
    } else {
        data = nullptr;
    }
}

myString& myString::operator=(const myString& other) {
    if (this != &other) {

        delete[] data; // liberar memoria previa

        size = other.size;
        if (size > 0) {
            data = new char[size + 1];
            copyString(data, other.data);
        } else {
            data = nullptr;
        }
    }
    return *this;
}



bool myString::operator==(const char* str) const
{
    int len = 0;
    while (str[len] != '\0')
        len++;

    if (size != len)
        return false;

    for (int i = 0; i < size; i++) {
        if (data[i] != str[i])
            return false;
    }
    return true;
}


int myString::getSize() const {
    return size;
}

const char* myString::getData() const {
    return data ? data : "";
}

myString::~myString() {
    delete[] data;
}





