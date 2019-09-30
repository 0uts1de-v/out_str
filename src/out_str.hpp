#ifndef OUTSIDE_STRING
#define OUTSIDE_STRING

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

class out_str {
  private:
    char *m_data;
    size_t m_size;
    size_t m_capacity;

  public:
    static constexpr size_t npos = -1;

    // constructor
    out_str();
    out_str(const size_t, const char);
    out_str(const char *);
    out_str(const out_str &);

    // destructor
    ~out_str();

    // operator
    char &operator[](const size_t);
    out_str &operator=(const char *);
    out_str &operator=(const out_str &);
    out_str operator+(const char *);
    out_str operator+(const out_str &);
    out_str &operator+=(const char *);
    out_str &operator+=(const out_str &);
    const bool operator==(const char *);
    const bool operator==(const out_str &);
    const bool operator!=(const char *);
    const bool operator!=(const out_str &);

    // member funcs
    const char *c_str() const { return m_data; }
    const size_t capacity() const { return m_capacity; }
    const size_t size() const { return m_size; }
    const char *data() const { return m_data; }
    const bool empty() const { return size() == 0; }

    void erase(size_t, size_t);
    void pop_back();
    out_str &append(size_t, char);
    void push_back(char);
};

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

const bool out_str::operator==(const char *str) {
    return size() == std::strlen(str) && std::memcmp(data(), str, std::min(size(), std::strlen(str))) == 0;
}

const bool out_str::operator==(const out_str &str) {
    return size() == str.size() && std::memcmp(data(), str.data(), std::min(size(), str.size())) == 0;
}

const bool out_str::operator!=(const char *str) {
    return !(*this == str);
}

const bool out_str::operator!=(const out_str &str) {
    return !(*this == str);
}

// member funcs
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

#endif
