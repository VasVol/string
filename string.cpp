#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& s) {
    return out << s.arr;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.clear();
    char c;
    in >> c;
    s.push_back(c);
    while (in.get(c) && c != '\n' && c != ' ') {
        s.push_back(c);
    }
    return in;
}

bool String::operator>(const String& str) const {
    return str < *this;
}

bool String::operator<=(const String& str) const {
    return !(*this > str);
}

bool String::operator>=(const String& str) const {
    return !(*this < str);
}

bool String::operator==(const String& str) const {
    if (sz != str.sz) {
        return false;
    }
    for (size_t i = 0; i < sz; ++i) {
        if (arr[i] != str[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& str) const {
    return !(*this == str);
}

bool String::operator<(const String& str) const {
    for (size_t i = 0; i < std::min(sz, str.sz); ++i) {
        if (arr[i] > str[i]) {
            return false;
        }
        if (arr[i] < str[i]) {
            return true;
        }
    }
    return sz < str.sz;
}

String& String::operator+(const String& str) {
    String* new_string = new String(*this);
    *new_string += str;
    return *new_string;
}

String& String::operator+(char c) {
    String* new_string = new String(*this);
    *new_string += c;
    return *new_string;
}

const char& String::back() const {
    return arr[sz - 1];
}

char& String::back() {
    return arr[sz - 1];
}

String& String::operator+=(char c) {
    push_back(c);
    return *this;
}

String& String::operator+=(const String& str) {
    if (sz + str.sz >= cap) {
        resize_array((sz + str.sz) * 2 + 1);
    }
    std::copy(str.arr, str.arr + str.sz + 1, arr + sz);
    sz += str.sz;
    return *this;
}

const char& String::operator[](size_t i) const {
    return arr[i];
}

char& String::operator[](size_t i) {
    return arr[i];
}

const char& String::front() const {
    return arr[0];
}

char& String::front() {
    return arr[0];
}

size_t String::length() const {
    return sz;
}

size_t String::size() const {
    return sz + 1;
}

size_t String::capacity() const {
    return cap;
}

char* String::data() const {
    return arr;
}

void String::pop_back() {
    --sz;
    arr[sz] = '\0';
}

void String::push_back(char c) {
    if (sz == cap - 1) {
        resize_array(cap * 2);
    }
    arr[sz] = c;
    ++sz;
    arr[sz] = '\0';
}

void String::clear() {
    sz = 0;
    arr[0] = '\0';
}

bool String::empty() const {
    return sz == 0;
}

void String::shrink_to_fit() {
    resize_array(sz + 1);
}

String& String::operator=(const String& str) {
    String copy = str;
    swap(copy);
    return *this;
}

String::~String() {
    delete[] arr;
}

String::String(const String& str)
    : arr(new char[str.sz + 1]), sz(str.sz), cap(str.sz + 1) {
    std::copy(str.arr, str.arr + sz + 1, arr);
}

String::String(const char* s) {
    sz = std::strlen(s);
    cap = sz + 1;
    arr = new char[cap];
    std::copy(s, s + sz + 1, arr);
}

String::String(size_t n, char c) : arr(new char[n + 1]), sz(n), cap(n + 1) {
    std::fill(arr, arr + sz, c);
    arr[cap - 1] = '\0';
}

String::String(char c) : String(1, c) {}

String::String() : arr(new char[1]), sz(0), cap(1) {
    arr[0] = '\0';
}

String::String(size_t start, size_t count, char* uk) {
    sz = count;
    cap = count + 1;
    arr = new char[cap];
    std::copy(uk + start, uk + start + count, arr);
}

void String::swap(String& str) {
    std::swap(arr, str.arr);
    std::swap(sz, str.sz);
    std::swap(cap, str.cap);
}

void String::resize_array(size_t new_size) {
    char* new_arr = new char[new_size];
    std::copy(arr, arr + sz + 1, new_arr);
    delete[] arr;
    arr = new_arr;
    cap = new_size;
}

String String::substr(size_t start, size_t count) const {
    return String(start, count, arr);
}

size_t String::find(const String& str) const {
    if (sz < str.sz) {
        return sz;
    }
    for (size_t i = 0; i <= sz - str.sz; ++i) {
        bool flag = true;
        for (size_t j = 0; j < str.sz; ++j) {
            if (arr[j + i] != str[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return sz;
}

size_t String::rfind(const String& str) const {
    if (sz < str.sz) {
        return sz;
    }
    for (size_t i = sz - str.sz;; --i) {
        bool flag = true;
        for (size_t j = 0; j < str.sz; ++j) {
            if (arr[j + i] != str[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
        if (i == 0) {
            break;
        }
    }
    return sz;
}

String& operator+(char c, const String& str) {
    String* new_string = new String(1, c);
    *new_string += str;
    return *new_string;
}

String& operator+(const char* str1, const String& str2) {
    String* new_string = new String(str1);
    *new_string += str2;
    return *new_string;
}

bool operator==(const char* str1, const String& str2) {
    return String(str1) == str2;
}

bool operator<(const char* str1, const String& str2) {
    return String(str1) < str2;
}

bool operator>(const char* str1, const String& str2) {
    return String(str1) > str2;
}

bool operator!=(const char* str1, const String& str2) {
    return String(str1) != str2;
}

bool operator<=(const char* str1, const String& str2) {
    return String(str1) <= str2;
}

bool operator>=(const char* str1, const String& str2) {
    return String(str1) >= str2;
}
