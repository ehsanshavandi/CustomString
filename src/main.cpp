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
    CustomString csExample("Ehsan Shavandi");
    string exLower = csExample.toLowerCase();
    string exUpper = csExample.toUpperCase();
    csExample.replace("Ehsan", "Ali");
    cout << csExample.data() << endl;
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
