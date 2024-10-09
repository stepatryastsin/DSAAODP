
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <memory>
#include <stdexcept>


class String {
public:
    String();
    String(const String& other);
    String(String&& other) noexcept;
    ~String();
    const char* c_str() const;
    int size() const;

private:
    char* _content;
    void copy(const char* str);
};


inline String::String()
{

}


inline String::String(const String& other)
{
}


inline String::String(String&& other) noexcept
{
}

inline String::~String()
{
}


inline const char* String::c_str() const
{
    return nullptr;
}

#endif // !VECTOR_H

