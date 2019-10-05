#ifndef ALUMINIUM_BASE64
#define ALUMINIUM_BASE64

#include <bitset>
#include <string>

#include "util.hpp"

namespace aluminium {
namespace base64 {

std::string base64encode(const char *plain_cstr) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string plain(plain_cstr), bitstr, encoded;

    for (unsigned int i = 0; i < plain.size(); ++i) {
        bitstr += std::bitset<8>(plain[i]).to_string();
    }

    for (unsigned int i = 0; i < bitstr.size() % 6; ++i) {
        bitstr += "0";
    }

    for (unsigned int i = 0; i < bitstr.size(); i += 6) {
        encoded += table[std::stoi(bitstr.substr(i, 6), nullptr, 2)];
    }

    for (unsigned int i = 0; i < encoded.size() % 4; ++i) {
        encoded += "=";
    }

    return encoded;
}

std::string base64encode_url(const char *plain_cstr) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    std::string plain(plain_cstr), bitstr, encoded;

    for (unsigned int i = 0; i < plain.size(); ++i) {
        bitstr += std::bitset<8>(plain[i]).to_string();
    }

    for (unsigned int i = 0; i < bitstr.size() % 6; ++i) {
        bitstr += "0";
    }

    for (unsigned int i = 0; i < bitstr.size(); i += 6) {
        encoded += table[std::stoi(bitstr.substr(i, 6), nullptr, 2)];
    }

    return encoded;
}

std::string base64decode(const char *code_cstr) {
    auto table = [](int x) { return (65 <= x && x <= 90) ? x - 65 : (97 <= x && x <= 122) ? x - 71 : (48 <= x && x <= 57) ? x + 4 : (x == 43) ? 62 : 63; };
    std::string code(code_cstr), bitstr, decoded;

    //code.erase(std::remove_if(code.begin(), code.end(), [](char c){return c == '=';}), code.end());
    aluminium::util::erase_if(code, [](char c) { return c == '='; });

    for (const auto &i : code) {
        bitstr += std::bitset<6>(table(i)).to_string();
    }

    bitstr.erase(bitstr.end() - (bitstr.size() % 8), bitstr.end());

    for (unsigned int i = 0; i < bitstr.size(); i += 8) {
        decoded += char(std::stoi(bitstr.substr(i, 8), nullptr, 2));
    }

    return decoded;
}

std::string base64decode_url(const char *code_cstr) {
    auto table = [](int x) { return (65 <= x && x <= 90) ? x - 65 : (97 <= x && x <= 122) ? x - 71 : (48 <= x && x <= 57) ? x + 4 : (x == 45) ? 62 : 63; };
    std::string code(code_cstr), bitstr, decoded;

    for (const auto &i : code) {
        bitstr += std::bitset<6>(table(i)).to_string();
    }

    bitstr.erase(bitstr.end() - (bitstr.size() % 8), bitstr.end());

    for (unsigned int i = 0; i < bitstr.size(); i += 8) {
        decoded += char(std::stoi(bitstr.substr(i, 8), nullptr, 2));
    }

    return decoded;
}

} // namespace base64
} // namespace aluminium

#endif
