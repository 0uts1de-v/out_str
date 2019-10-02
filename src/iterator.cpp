#include <cstdint>

#include "out_str.hpp"

// constructor
out_str_iter::out_str_iter() {
    m_out_str = nullptr;
    m_index = 0;
}

out_str_iter::out_str_iter(out_str *ostr, size_t index) {
    m_out_str = ostr;
    m_index = index;
}

out_str_iter::out_str_iter(const out_str_iter &iterator) {
    m_out_str = iterator.m_out_str;
    m_index = iterator.m_index;
}

// operator
char &out_str_iter::operator*() {
    return m_out_str->m_data[m_index];
}

out_str_iter &out_str_iter::operator++() {
    ++m_index;
    return *this;
}

out_str_iter &out_str_iter::operator++(int) {
    ++m_index;
    return *this;
}

out_str_iter &out_str_iter::operator--() {
    --m_index;
    return *this;
}

out_str_iter &out_str_iter::operator--(int) {
    --m_index;
    return *this;
}

out_str_iter out_str_iter::operator+(size_t n) {
    auto ret = *this;
    ret.m_index += n;
    return ret;
}

out_str_iter out_str_iter::operator-(size_t n) {
    auto ret = *this;
    ret.m_index -= n;
    return ret;
}

ptrdiff_t out_str_iter::operator-(const out_str_iter &iterator) {
    return m_index - iterator.m_index;
}

out_str_iter &out_str_iter::operator+=(size_t n) {
    m_index += n;
    return *this;
}

out_str_iter &out_str_iter::operator-=(size_t n) {
    m_index -= n;
    return *this;
}

out_str_iter &out_str_iter::operator=(const out_str_iter &iterator) {
    m_out_str = iterator.m_out_str;
    m_index = iterator.m_index;
    return *this;
}

bool out_str_iter::operator==(const out_str_iter &iterator) {
    return m_out_str == iterator.m_out_str && m_index == iterator.m_index;
}

bool out_str_iter::operator!=(const out_str_iter &iterator) {
    return !(*this == iterator);
}

bool out_str_iter::operator<(const out_str_iter &iterator) {
    return m_index < iterator.m_index;
}

bool out_str_iter::operator>(const out_str_iter &iterator) {
    return m_index > iterator.m_index;
}

bool out_str_iter::operator<=(const out_str_iter &iterator) {
    return m_index <= iterator.m_index;
}

bool out_str_iter::operator>=(const out_str_iter &iterator) {
    return m_index >= iterator.m_index;
}
