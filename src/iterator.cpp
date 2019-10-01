#ifndef OUTSIDE_STRING_ITERATOR
#define OUTSIDE_STRING_ITERATOR

#include <cstdint>

#include "out_str.hpp"


// constructor
out_str_iter::out_str_iter() {
    m_out_str = nullptr;
    m_index = SIZE_MAX;
}

out_str_iter::out_str_iter(out_str *ostr, size_t index) {
    m_out_str = ostr;
    m_index = (index <= m_out_str->size() ? index : SIZE_MAX);
}

out_str_iter::out_str_iter(const out_str_iter &iterator) {
    m_out_str = iterator.m_out_str;
    m_index = iterator.m_index;
}

// operator
char &out_str_iter::operator*() {
    static char dummy;
    return (m_index != SIZE_MAX ? m_out_str->m_data[m_index] : dummy);
}

out_str_iter &out_str_iter::operator++() {
    ++m_index;
    return *this;
}

out_str_iter &out_str_iter::operator++(int) {
    ++m_index;
    return *this;
}

bool out_str_iter::operator==(const out_str_iter &iterator) {
    return m_out_str == iterator.m_out_str && m_index == iterator.m_index;
}

bool out_str_iter::operator!=(const out_str_iter &iterator) {
    return !(*this == iterator);
}

#endif
