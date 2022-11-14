#include <algorithm>
#include <cstring>
#include <iostream>

class String {
  private:
    char* arr;
    size_t sz;
    size_t cap;
    void resize_array(size_t new_size);
    void swap(String& str);
    String(size_t start, size_t count, char* uk);

  public:
    String();
    String(size_t n, char c);
    String(char c);
    String(const char* s);
    String(const String& str);
    ~String();
    String& operator=(const String& str);
    void shrink_to_fit();
    bool empty() const;
    void clear();
    void push_back(char c);
    void pop_back();
    size_t length() const;
    size_t size() const;
    size_t capacity() const;
    char* data() const;
    const char& operator[](size_t i) const;
    char& operator[](size_t i);
    const char& front() const;
    char& front();
    const char& back() const;
    char& back();
    String& operator+=(char c);
    String& operator+=(const String& str);
    String& operator+(const String& str);
    String& operator+(char c);
    friend String& operator+(char c, const String& str);
    friend String& operator+(const char* str1, const String& str2);
    bool operator==(const String& str) const;
    bool operator!=(const String& str) const;
    bool operator<(const String& str) const;
    bool operator>(const String& str) const;
    bool operator<=(const String& str) const;
    bool operator>=(const String& str) const;
    friend bool operator==(const char* str1, const String& str2);
    friend bool operator<(const char* str1, const String& str2);
    friend bool operator>(const char* str1, const String& str2);
    friend bool operator!=(const char* str1, const String& str2);
    friend bool operator<=(const char* str1, const String& str2);
    friend bool operator>=(const char* str1, const String& str2);
    friend std::ostream& operator<<(std::ostream& out, const String& s);
    friend std::istream& operator>>(std::istream& in, String& s);
    String substr(size_t start, size_t count) const;
    size_t find(const String& str) const;
    size_t rfind(const String& str) const;
};
