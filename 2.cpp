#include <regex>
#include <string> // Use angle brackets for standard library includes
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)?
               str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};


int main() {
    string a = "AAAAAAAAA";
    string b = "AAACCC";

    Solution solution;
    string res = solution.gcdOfStrings(a, b);

    cout << res;
}