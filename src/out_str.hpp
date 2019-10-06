#ifndef OUT_STR_HPP
#define OUT_STR_HPP

#include <cctype>
#include <cstddef>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>

namespace outside_string {

class out_str_iter;

class out_str {
    friend out_str_iter;
    using iterator = out_str_iter;

  private:
    char *m_data;
    std::size_t m_size;
    std::size_t m_capacity;

  public:
    static constexpr std::size_t npos = -1;

    // constructor
    out_str();
    out_str(const std::size_t, const char);
    out_str(const char *);
    out_str(const out_str &);
    out_str(const out_str &, std::size_t, std::size_t);
    out_str(const std::string &);
    out_str(const std::string &, std::size_t, std::size_t);

    // destructor
    ~out_str();

    // operator
    char &operator[](const std::size_t);
    const char &operator[](const std::size_t) const;
    out_str &operator=(const char *);
    out_str &operator=(const out_str &);
    out_str &operator=(const std::string &);
    out_str operator+(const char);
    out_str operator+(const char *);
    out_str operator+(const out_str &);
    out_str &operator+=(const char);
    out_str &operator+=(const char *);
    out_str &operator+=(const out_str &);
    out_str operator*(std::size_t);
    out_str &operator*=(std::size_t);
    bool operator==(const char *);
    bool operator==(const out_str &);
    bool operator!=(const char *);
    bool operator!=(const out_str &);

    // member funcs
    const char *c_str() const;
    const char *data() const;
    constexpr std::size_t capacity() const { return m_capacity; }
    constexpr std::size_t size() const { return m_size; }
    constexpr bool empty() const { return size() == 0; }

    void erase(std::size_t pos = 0, std::size_t n = npos);
    void pop_back();
    out_str &append(std::size_t, char);
    void push_back(char);
    void shrink_to_fit();
    out_str substr(std::size_t pos = 0, std::size_t n = npos) const;

    out_str upper_case(std::size_t pos = 0, std::size_t n = npos) const;
    out_str lower_case(std::size_t pos = 0, std::size_t n = npos) const;
    out_str rot13(std::size_t pos = 0, std::size_t n = npos) const;
    out_str base64_encode(bool urlSafe = false) const;
    out_str base64_decode(bool urlSafe = false) const;

    // iterator
    iterator begin();
    iterator end();
};

class out_str_iter {
    friend out_str;

  private:
    std::size_t m_index;
    out_str *m_out_str;

    // constructor
    out_str_iter();
    out_str_iter(out_str *, std::size_t);

  public:
    using difference_type = ptrdiff_t;
    using value_type = char;
    using pointer = char *;
    using reference = char &;
    using iterator_category = std::random_access_iterator_tag;

    // constructor
    out_str_iter(const out_str_iter &);

    // operator
    char &operator*();
    out_str_iter &operator++();
    out_str_iter &operator++(int);
    out_str_iter &operator--();
    out_str_iter &operator--(int);
    out_str_iter operator+(std::size_t);
    out_str_iter operator-(std::size_t);
    std::ptrdiff_t operator-(const out_str_iter &);
    out_str_iter &operator+=(std::size_t);
    out_str_iter &operator-=(std::size_t);
    out_str_iter &operator=(const out_str_iter &);
    bool operator==(const out_str_iter &);
    bool operator!=(const out_str_iter &);
    bool operator<(const out_str_iter &);
    bool operator>(const out_str_iter &);
    bool operator<=(const out_str_iter &);
    bool operator>=(const out_str_iter &);
};

// overload for iostream
std::ostream &operator<<(std::ostream &, const outside_string::out_str &);
std::istream &operator>>(std::istream &, outside_string::out_str &);

} // namespace outside_string

#endif
