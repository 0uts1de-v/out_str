#include <iostream>
#include <algorithm>
#include <random>
#include <string>

#include "src/out_str.hpp"

using std::cout;
using std::cin;
using outside_string::out_str;

int main() {
    /*
    const out_str str("abcd");
    cout << str[0];
    */
    /*
    out_str str;
    cin >> str;
    cout << str << ", siz:" << str.size() << ", cap:" << str.capacity() << "\n";
    str += 'a';
    cout << str << ", siz:" << str.size() << ", cap:" << str.capacity() << "\n";
    */
    /*
    std::string str("abcde");
    out_str ostr(str);
    cout << ostr << ", " << ostr.size() << ", " << ostr.capacity() << "\n";
    */
    
    out_str str;
    cin >> str;
    cout << str << ", " << str.size() << ", " << str.capacity() << "\n";
    cout << str.upper_case() << ", " << str.upper_case().size() << ", " << str.upper_case().capacity() << "\n";
    cout << str.lower_case() << ", " << str.lower_case().size() << ", " << str.lower_case().capacity() << "\n";
    cout << str.rot13() << ", " << str.rot13().size() << ", " << str.rot13().capacity() << "\n";
    cout << str.base64_encode() << ", " << str.base64_encode().size() << ", " << str.base64_encode().capacity() << "\n";
    cout << str.base64_encode(true) << ", " << str.base64_encode(true).size() << ", " << str.base64_encode(true).capacity() << "\n";
    cout << str.substr(6, 3) << ", " << str.substr(6, 3).size() << ", " << str.substr(6, 3).capacity() << "\n";
    
    /*
    out_str str("abc");
    cout << str << ", " << str.size() << ", " << str.capacity() << "\n";
    str += "d";
    cout << str << ", " << str.size() << ", " << str.capacity() << "\n";
    str.shrink_to_fit();
    cout << str << ", " << str.size() << ", " << str.capacity() << "\n";
    std::string tmp; std::cin >> tmp;
    str = tmp;
    cout << str << ", " << str.size() << ", " << str.capacity() << "\n";
    */
    /*
    std::random_device rd;
    std::mt19937 mt(rd());
    out_str str("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    std::shuffle(str.begin(), str.end(), mt);
    for (const auto &i : str) cout << i << ",";
    */
    /*
    {
        out_str str(10, 'x');
        str.push_back('z');
        cout << str << "\n"
             << str.size() << ", " << str.capacity() << "\n";
    }
    out_str str("test");
    cout << str << ", " << str.size() << "\n";
    str += "aaa";
    cout << str << ", " << str.size() << "\n";
    str = "b";
    cout << str << ", " << str.size() << "\n";
    str = str + "ccc";
    cout << str << ", " << str.size() << "\n";
    str[0] = 'a';
    cout << str << ", " << str.size() << "\n";
    out_str st2 = "vvvvv";
    str += st2;
    cout << str << ", " << str.size() << "\n";
    str = "abc";
    str.pop_back();
    cout << str << ", " << str.size() << "\n";
    str.push_back('c');
    cout << str << ", " << str.size() << "\n";

    out_str qwe("abcde");
    cout << (qwe == "abcde") << ", " << (qwe == "abc") << ", " << (qwe != "abcde") << ", " << (qwe != "abc") << "\n";
    qwe *= 50;
    cout << qwe << ", " << qwe.size() << "\n";
    */
}
