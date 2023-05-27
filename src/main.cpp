#include "customstring.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    //  string example = "Ehsan SHaavnadi HellO";
    CustomString csExample("Ehsan Shavandi Ehsan");
    string exLower = csExample.toLowerCase();
    string exUpper = csExample.toUpperCase();
    //    csExample.replaceAll("Ehsan", "Ali");
    //    csExample.replaceIgnCase("ehSan", "Ali");
    csExample.replaceAllIgnCase("ehSan", "Ali");
    //    cout << csExample.data() << endl;

    CustomString dna("GATATATACAGGTACCCAATTTACAGATACAAATTTTAAGGAAGAGATATACACACA");
    //    size_t posFound = dna.oldFind("GATACA");
    //    if (posFound != string::npos)
    //    {
    //        cout << "Found at " << posFound << endl;
    //    }

    CustomString name("can i match my name Ehsan");
    //    posFound = name.oldFindIgnorCase("ehsan");
    //    if (posFound != string::npos)
    //        cout << "Found at " << posFound << endl;
    size_t posFound = dna.findBoyer("GATACA");
    //    if (posFound != string::npos)
    //    {
    //        cout << "Found at " << posFound << endl;
    //    }

    // REGEX
    CustomString example(
        "Meanwhile LLVM has released apt 09121234567 packages for LLVM 13 and 14 "
        "but "
        "out-of-the 0912-123-4567 box clang-format-13, 0912 123 4567 clang-tidy-13, ... are "
        "not available "
        "via apt-get install clang-format-13.How 0912 1111111 can I install clang-format-13 "
        "on Ubuntu 0912-1234567 18.04?");

    std::regex mobilePattern(
        R"delim(\d{11}|\d{4}[\s,-]\d{3}[\s,-]\d{4}|\d{4}[\s,-]\d{7})delim");	// matches words

    vector<string> foundsAll = example.findPattern(mobilePattern);
    for_each(foundsAll.begin(), foundsAll.end(), [](const string& item) { cout << item << endl; });
    //    cout << exLower << endl;
    //    cout << exUpper << endl;
    //    //    stringstream ss;
    //    unordered_map<string, int> wordCount;
    //    vector<string> myArr{"apple", "orange", "banana", "apple", "banana",
    //    "orange", "apple", "alaki"}; for (auto it1 = myArr.begin(); it1 !=
    //    myArr.end(); ++it1) {
    //        auto ptrFound = wordCount.find(*it1);
    //        if (ptrFound == wordCount.end())
    //            wordCount[*it1] = 1;

    //        else
    //            continue;
    //        for (auto it2 = it1 + 1; it2 < myArr.end(); ++it2) {
    //            if (*it1 == *it2) {
    //                //                cout << "it1: " << *it1 << "\t" <<
    //                *it2 << endl; wordCount[*it1]++;
    //            }
    //        }
    //    }

    //    for (const auto &p : wordCount)
    //        cout << p.first << "\t" << p.second << endl;
    return 0;
}
