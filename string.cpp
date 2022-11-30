#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& s) {
    return out << s.data();
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

int operator<=>(const String& str1, const String& str2) {
    size_t len = std::min(str1.size(), str2.size());
    int ans = memcmp(str1.data(), str2.data(), len);
    if (ans != 0) {
        return ans;
    }
    if (str1.size() < str2.size()) {
        return -1;
    }
    if (str1.size() > str2.size()) {
        return 1;
    }
    return 0;
}

bool operator==(const String& str1, const String& str2) {
    return (str1 <=> str2) == 0;
}

String operator+(const String& str1, const String& str2) {
    String new_string(str1);
    new_string += str2;
    return new_string;
}

String operator+(const String& str, char c) {
    String new_string(str);
    new_string += c;
    return new_string;
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
    return sz;
}

size_t String::capacity() const {
    return cap - 1;
}

char* String::data() {
    return arr;
}

const char* String::data() const {
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
    : sz(str.sz), cap(str.sz + 1), arr(new char[str.sz + 1]) {
    std::copy(str.arr, str.arr + sz + 1, arr);
}

String::String(const char* s)
    : sz(std::strlen(s)), cap(sz + 1), arr(new char[cap]) {
    std::copy(s, s + sz + 1, arr);
}

String::String(size_t n, char c) : sz(n), cap(n + 1), arr(new char[n + 1]) {
    std::fill(arr, arr + sz, c);
    arr[cap - 1] = '\0';
}

String::String(char c) : String(1, c) {}

String::String() : sz(0), cap(1), arr(new char[1]) {
    arr[0] = '\0';
}

String::String(size_t start, size_t count, char* ptr)
    : sz(count), cap(count + 1), arr(new char[cap]) {
    std::copy(ptr + start, ptr + start + count, arr);
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

bool mem_equal(void* ptr1, void* ptr2, size_t k) {
    return std::memcmp(ptr1, ptr2, k) == 0;
}

size_t String::find(const String& str) const {
    if (sz < str.sz) {
        return sz;
    }
    for (size_t i = 0; i <= sz - str.sz; ++i) {
        if (mem_equal(arr + i, str.arr, str.sz)) {
            return i;
        }
    }
    return sz;
}

size_t String::rfind(const String& str) const {
    for (int64_t i = static_cast<int64_t>(sz) - str.sz; i >= 0; --i) {
        if (mem_equal(arr + i, str.arr, str.sz)) {
            return i;
        }
    }
    return sz;
}

String operator+(char c, const String& str) {
    String new_string(1, c);
    new_string += str;
    return new_string;
}

String operator+(const char* str1, const String& str2) {
    String new_string(str1);
    new_string += str2;
    return new_string;
}
