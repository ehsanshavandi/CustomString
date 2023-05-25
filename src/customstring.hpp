// CustomString.hpp

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

class CustomString {
  /*! @class
   *  @brief This class is for leverage functionality of std::string class.
   *
   *
   *  This class has a m_data private member and use composition relationship
   *  std::string does not have virtual destructor and virtual member function
   *  and that is why I use composition relationship
   */
 public:
  /**
   * A constructor for c-style string(char*) input
   * @param cStr a char const*
   */
  explicit CustomString(char const* cStr) : m_data(cStr) {}
  /**
   * A constructor for standard string in STL
   * @param str a const string&
   */
  explicit CustomString(const string& str) : m_data(str) {}

  /**
   * @brief toLowerCase
   * @param str a const string& str
   * @return std::string
   */
  static string toLowerCase(const string& str);
  /**
   * @brief toLowerCase
   * @return std::string
   */
  string toLowerCase();
  /**
   * @brief toUpperCase
   * @param str a const string&
   * @return std::string
   */
  static string toUpperCase(const string& str);
  /**
   * @brief toUpperCase
   * @return std::string
   */
  string toUpperCase();

  /**
   * @brief append
   * @param str a const std::string& str
   */
  void append(const std::string& str);
  /**
   * @brief length
   * @return size_t
   */
  size_t length() const;

  /**
   * @brief operator []
   * @param index a size_t
   * @return char&
   */
  char& operator[](size_t index);

  /**
   * @brief data
   * @return std::string
   */
  string data() const;

 private:
  string m_data; /**< std::string */
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
