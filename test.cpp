#include <iostream>

#include "src/out_str.hpp"

using std::cout;

int main() {
    out_str str("test");
    str *= 100;
    for (const auto &i : str) cout << i << ",";
    /*
    {
        out_str str(10, 'x');
        str.push_back('z');
        cout << str.c_str() << "\n"
             << str.size() << ", " << str.capacity() << "\n";
    }
    out_str str("test");
    cout << str.c_str() << ", " << str.size() << "\n";
    str += "aaa";
    cout << str.c_str() << ", " << str.size() << "\n";
    str = "b";
    cout << str.c_str() << ", " << str.size() << "\n";
    str = str + "ccc";
    cout << str.c_str() << ", " << str.size() << "\n";
    str[0] = 'a';
    cout << str.c_str() << ", " << str.size() << "\n";
    out_str st2 = "vvvvv";
    str += st2;
    cout << str.c_str() << ", " << str.size() << "\n";
    str = "abc";
    str.pop_back();
    cout << str.c_str() << ", " << str.size() << "\n";
    str.push_back('c');
    cout << str.c_str() << ", " << str.size() << "\n";

    out_str qwe("abcde");
    cout << (qwe == "abcde") << ", " << (qwe == "abc") << ", " << (qwe != "abcde") << ", " << (qwe != "abc") << "\n";
    qwe *= 50;
    cout << qwe.c_str() << ", " << qwe.size() << "\n";
    */
}
