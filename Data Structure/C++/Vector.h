
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    bool operator==(const Vector& other) const;
    size_t size() const;

    const T& operator[](size_t index) const;
    T& operator[](size_t index);

    void push_back(const T& value);

private:
    std::unique_ptr<T[]> _contentss;
    size_t _size;
    size_t _capacity;

    void copy(const Vector& other);
    void reserve(size_t new_capacity);
};

template<typename T>
Vector<T>::Vector() : _contentss(nullptr), _size(0), _capacity(0) {}

template<typename T>
Vector<T>::Vector(const Vector& other) : _size(other._size), _capacity(other._capacity) {
    copy(other);
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept : _contentss(std::move(other._contentss)), _size(other._size), _capacity(other._capacity) {
    other._size = 0;
    other._capacity = 0;
}

template<typename T>
Vector<T>::~Vector() {}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        _contentss.reset();
        _size = other._size;
        _capacity = other._capacity;
        copy(other);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        _contentss = std::move(other._contentss);
        _size = other._size;
        _capacity = other._capacity;

        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (_size != other._size) return false;
    for (size_t i = 0; i < _size; ++i) {
        if (_contentss[i] != other._contentss[i]) return false;
    }
    return true;
}

template<typename T>
size_t Vector<T>::size() const {
    return _size;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= _size) throw std::out_of_range("Index out of bounds");
    return _contentss[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= _size) throw std::out_of_range("Index out of bounds");
    return _contentss[index];
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    _contentss[_size++] = value;
}

template<typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= _capacity) return;

    std::unique_ptr<T[]> new_contentss = std::make_unique<T[]>(new_capacity);

    for (size_t i = 0; i < _size; ++i) {
        new_contentss[i] = std::move(_contentss[i]);
    }

    _contentss = std::move(new_contentss);
    _capacity = new_capacity;
}

template<typename T>
void Vector<T>::copy(const Vector& other) {
    _contentss = std::make_unique<T[]>(_capacity);
    for (size_t i = 0; i < _size; ++i) {
        _contentss[i] = other._contentss[i];
    }
}


#endif // !VECTOR_H

