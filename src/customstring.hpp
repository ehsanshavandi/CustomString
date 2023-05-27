// CustomString.hpp

#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <regex>
#include <string>

class CustomString
{
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
    explicit CustomString(char const* cStr) : m_data(cStr)
    {
    }
    /**
     * A constructor for standard string in STL
     * @param str a const string&
     */
    explicit CustomString(const std::string& str) : m_data(str)
    {
    }
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
    std::string data() const;

    /**
     * @static
     * @brief toLowerCase
     * @param str a const string& str
     * @return std::string
     */
    static std::string toLowerCase(const std::string& str);
    /**
     * @brief toLowerCase
     * @return std::string
     */
    std::string toLowerCase();
    /**
     * @static
     * @brief toUpperCase
     * @param str a const string&
     * @return std::string
     */
    static std::string toUpperCase(const std::string& str);
    /**
     * @brief toUpperCase
     * @return std::string
     */
    std::string toUpperCase();

    /**
     * @brief replace
     * @param str1 a const char*
     * @param str2 a const char*
     */
    void replace(const std::string& str1, const std::string& str2);

    /**
     * @brief oldFind
     * @param str is const string&
     * @return position which found
     */
    std::size_t oldFind(const std::string& str);
    /**
     * @brief oldFindIgnorCase
     * @param str is a const string&
     * @return position which found
     */
    std::size_t oldFindIgnorCase(const std::string& str);
    /**
     * @brief findBoyer
     * boyer moor horsepol algorithm is used
     * @param str is a const string&
     * @return position which found
     */
    std::size_t findBoyer(const std::string& str);

private:
    std::string m_data; /**< std::string */

    /**
     * @brief m_srearchString a private member funtion
     * which used for searching character by character
     * @param ref is a main string
     * @param str is a wanted string
     * @param pred predicte function
     * @return std::string::const_iterator
     */
    std::string::const_iterator m_srearchString(const std::string& ref,
        const std::string& str,
        std::function<bool(unsigned char, unsigned char)> pred = std::equal_to<unsigned char>());

    /**
     * @brief predicate function for searching in string case insensitively
     */
    std::function<bool(unsigned char, unsigned char)> m_equal_iggnore_case =
        [](unsigned char rc, unsigned char sc) -> bool { return tolower(rc) == tolower(sc); };
};

inline std::string CustomString::data() const
{
    return m_data;
}

std::string CustomString::toLowerCase(const std::string& str)
{
    std::string tmp;
    transform(str.begin(),
        str.end(),
        std::back_inserter<std::string>(tmp),
        [](unsigned char c) { return std::tolower(c); });

    return tmp;
}

std::string CustomString::toLowerCase()
{
    std::string tmp;
    transform(m_data.begin(),
        m_data.end(),
        std::back_inserter<std::string>(tmp),
        [](unsigned char c) { return std::tolower(c); });

    return tmp;
}

std::string CustomString::toUpperCase(const std::string& str)
{
    std::string tmp;
    transform(str.begin(),
        str.end(),
        std::back_inserter<std::string>(tmp),
        [](unsigned char c) { return std::toupper(c); });

    return tmp;
}

std::string CustomString::toUpperCase()
{
    std::string tmp;
    transform(m_data.begin(),
        m_data.end(),
        std::back_inserter<std::string>(tmp),
        [](unsigned char c) { return std::toupper(c); });

    return tmp;
}

void CustomString::replace(const std::string& str1, const std::string& str2)
{
    size_t pos = m_data.find(str1);
    if (pos != std::string::npos)
        m_data.replace(pos, std::string(str1).length(), str2);
}

std::size_t CustomString::oldFind(const std::string& str)
{
    std::string::const_iterator it = m_srearchString(m_data, str);
    if (it != m_data.end())
        return std::distance(m_data.cbegin(), it);
    else
        return std::string::npos;
}

inline size_t CustomString::oldFindIgnorCase(const std::string& str)
{
    std::string::const_iterator it = m_srearchString(m_data, str, m_equal_iggnore_case);
    if (it != m_data.end())
        return std::distance(m_data.cbegin(), it);
    else
        return std::string::npos;
}

size_t CustomString::findBoyer(const std::string& str)
{
    auto it = std::search(
        m_data.begin(), m_data.end(), std::boyer_moore_horspool_searcher(str.begin(), str.end()));
    if (it != m_data.end())
        return std::distance(m_data.begin(), it);
    else
        return std::string::npos;
}

std::string::const_iterator CustomString::m_srearchString(const std::string& ref,
    const std::string& str,
    std::function<bool(unsigned char, unsigned char)> pred)
{
    return search(ref.begin(), ref.end(), str.begin(), str.end(), pred);
}

inline void CustomString::append(const std::string& str)
{
    m_data += str;
}

inline size_t CustomString::length() const
{
    return m_data.length();
}

inline char& CustomString::operator[](size_t index)
{
    return m_data[index];
}
