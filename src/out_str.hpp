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
    size_t capacity() const;
    size_t size() const;
    const char *data() const;
    bool empty() const;

    void erase(size_t, size_t);
    void pop_back();
    out_str &append(size_t, char);
    void push_back(char);

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
    // constructor
    out_str_iter(const out_str_iter &);

    // operator
    char &operator*();
    out_str_iter &operator++();
    out_str_iter &operator++(int);
    bool operator==(const out_str_iter &);
    bool operator!=(const out_str_iter &);
};

