// CustomString.hpp

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

class CustomString {
 public:
  explicit CustomString(char const* cStr) : m_data(cStr) {}
  explicit CustomString(const string& str) : m_data(str) {}

  static string toLowerCase(const string& str);
  string toLowerCase();
  static string toUpperCase(const string& str);
  string toUpperCase();

  void append(const std::string& str);
  size_t length() const;

  char& operator[](size_t index);

  string data() const;

 private:
  string m_data;
};

inline string CustomString::data() const { return m_data; }

string CustomString::toLowerCase(string& str) {
  string tmp;
  transform(str.begin(), str.end(), back_inserter<string>(tmp),
            [](unsigned char c) { return std::tolower(c); });

  return tmp;
}

inline string CustomString::toLowerCase() {
  string tmp;
  transform(m_data.begin(), m_data.end(), back_inserter<string>(tmp),
            [](unsigned char c) { return std::tolower(c); });

  return tmp;
}

inline string CustomString::toUpperCase(string& str) {
  string tmp;
  transform(str.begin(), str.end(), back_inserter<string>(tmp),
            [](unsigned char c) { return std::toupper(c); });

  return tmp;
}

string CustomString::toUpperCase() {
  string tmp;
  transform(m_data.begin(), m_data.end(), back_inserter<string>(tmp),
            [](unsigned char c) { return std::toupper(c); });

  return tmp;
}

inline void CustomString::append(const string& str) { m_data += str; }

inline size_t CustomString::length() const { return m_data.length(); }

inline char& CustomString::operator[](size_t index) { return m_data[index]; }
