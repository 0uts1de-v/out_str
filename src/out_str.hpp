#ifndef OUT_STR_HPP
#define OUT_STR_HPP

#include <iterator>

class out_str_iter;

class out_str {
    friend out_str_iter;
    using iterator = out_str_iter;

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
    out_str operator*(size_t);
    out_str &operator*=(size_t);
    bool operator==(const char *);
    bool operator==(const out_str &);
    bool operator!=(const char *);
    bool operator!=(const out_str &);

    // member funcs
    const char *c_str() const;
    constexpr size_t capacity() const { return m_capacity; }
    constexpr size_t size() const { return m_size; }
    const char *data() const;
    constexpr bool empty() const { return size() == 0; }

    void erase(size_t, size_t);
    void pop_back();
    out_str &append(size_t, char);
    void push_back(char);
    void shrink_to_fit();

    // iterator
    iterator begin();
    iterator end();
};

class out_str_iter {
    friend out_str;

  private:
    size_t m_index;
    out_str *m_out_str;

    // constructor
    out_str_iter();
    out_str_iter(out_str *, size_t);

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
    out_str_iter operator+(size_t);
    out_str_iter operator-(size_t);
    ptrdiff_t operator-(const out_str_iter &);
    out_str_iter &operator+=(size_t);
    out_str_iter &operator-=(size_t);
    out_str_iter &operator=(const out_str_iter &);
    bool operator==(const out_str_iter &);
    bool operator!=(const out_str_iter &);
    bool operator<(const out_str_iter &);
    bool operator>(const out_str_iter &);
    bool operator<=(const out_str_iter &);
    bool operator>=(const out_str_iter &);
};

#endif
