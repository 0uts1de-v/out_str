#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

#include "out_str.hpp"

// constructor
out_str::out_str() {
    m_capacity = m_size = 0;
    m_data = new char[1];
    m_data[0] = '\0';
}

out_str::out_str(const size_t n, const char c) {
    m_capacity = m_size = n;
    m_data = new char[n + 1];
    for (size_t i = 0; i < n; ++i)
        m_data[i] = c;
    m_data[n] = '\0';
}

out_str::out_str(const char *str) {
    m_capacity = m_size = std::strlen(str);
    m_data = new char[m_capacity + 1];
    std::memcpy(m_data, str, m_size);
}

out_str::out_str(const out_str &str) {
    m_capacity = str.capacity();
    m_size = str.size();
    m_data = new char[m_capacity + 1];
    std::memcpy(m_data, str.data(), m_size + 1);
}

// destructor
out_str::~out_str() {
    delete[] m_data;
}

// operator
char &out_str::operator[](const size_t n) {
    return m_data[n];
}

out_str &out_str::operator=(const char *str) {
    m_size = std::strlen(str);
    if (m_capacity < m_size) {
        m_capacity = m_size;
        delete[] m_data;
        m_data = new char[m_capacity + 1];
    }
    std::memcpy(m_data, str, m_size + 1);
    return *this;
}

out_str &out_str::operator=(const out_str &str) {
    m_size = str.size();
    if (m_capacity < m_size) {
        m_capacity = m_size;
        delete[] m_data;
        m_data = new char[m_capacity + 1];
    }
    std::memcpy(m_data, str.data(), m_size + 1);
    return *this;
}

out_str out_str::operator+(const char *str) {
    out_str ret(data());
    ret += str;
    return ret;
}

out_str out_str::operator+(const out_str &str) {
    out_str ret(data());
    ret += str.data();
    return ret;
}

out_str &out_str::operator+=(const char *str) {
    auto old_size = size();
    m_size += std::strlen(str);
    if (capacity() < size()) {
        out_str old(*this);
        auto old_data = old.data();
        while (capacity() < size())
            m_capacity *= 2;
        delete[] m_data;
        m_data = new char[capacity() + 1];
        std::memcpy(m_data, old_data, old_size);
    }
    std::memcpy(m_data + old_size, str, std::strlen(str) + 1);
    return *this;
}

out_str &out_str::operator+=(const out_str &str) {
    auto old_size = size();
    m_size += str.size();
    if (capacity() < size()) {
        out_str old(*this);
        auto old_data = old.data();
        while (capacity() < size())
            m_capacity *= 2;
        delete[] m_data;
        m_data = new char[capacity() + 1];
        std::memcpy(m_data, old_data, old_size);
    }
    std::memcpy(m_data + old_size, str.data(), str.size() + 1);
    return *this;
}

out_str out_str::operator*(size_t n) {
    auto ret = *this;
    for (size_t i = 1; i < n; ++i)
        ret += data();
    return ret;
}

out_str &out_str::operator*=(size_t n) {
    out_str tmp(*this);
    for (size_t i = 1; i < n; ++i)
        tmp += data();
    *this = tmp;
    return *this;
}

bool out_str::operator==(const char *str) {
    return size() == std::strlen(str) && std::memcmp(data(), str, std::min(size(), std::strlen(str))) == 0;
}

bool out_str::operator==(const out_str &str) {
    return size() == str.size() && std::memcmp(data(), str.data(), std::min(size(), str.size())) == 0;
}

bool out_str::operator!=(const char *str) {
    return !(*this == str);
}

bool out_str::operator!=(const out_str &str) {
    return !(*this == str);
}

// member funcs
const char *out_str::c_str() const {
    return m_data;
}

size_t out_str::capacity() const {
    return m_capacity;
}

size_t out_str::size() const {
    return m_size;
}

const char *out_str::data() const {
    return m_data;
}

bool out_str::empty() const {
    return size() == 0;
}

void out_str::erase(size_t pos = 0, size_t n = npos) {
    if (pos > size())
        throw std::out_of_range("out_str");
    auto xlen = std::min(n, size() - pos);
    m_size -= xlen;
    m_data[size()] = '\0';
}

void out_str::pop_back() {
    erase(size() - 1, 1);
}

out_str &out_str::append(size_t n, char c) {
    out_str tmp(n, c);
    *this += tmp;
    return *this;
}

void out_str::push_back(char c) {
    append(1, c);
}

void out_str::shrink_to_fit() {
    m_capacity = size();
    out_str tmp(*this);
    delete[] m_data;
    m_data = new char[capacity() + 1];
    std::memcpy(m_data, tmp.data(), size() + 1);
}

// iterator
out_str::iterator out_str::begin() {
    return iterator(this, 0);
}

out_str::iterator out_str::end() {
    return iterator(this, size());
}