// CustomString.hpp

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

class CustomString : public string {
 public:
  explicit CustomString(char const* cStr) : m_data(cStr) {}
  explicit CustomString(string& str) : m_data(str) {}

  string data() const;

  static string toLowerCase(string& str);
  string toLowerCase();
  static string toUpperCase(string& str);
  string toUpperCase();

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
