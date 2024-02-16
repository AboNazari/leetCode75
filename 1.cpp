#include <iostream>

using namespace std;

class Solution {
public:
    std::string mergeAlternately(string word1, string word2) {
        std::string result;
        int size = word1.size() + word2.size();
        for (int a = 0; a < size; a++) {
            if (word1.size() > a) {
                result.push_back(word1[a]);
            }
            if (word2.size() > a ) {
                result.push_back(word2[a]);
            }
        }
        cout << result;
        return result;
    }
};

int main() {
    string a = "abc";
    string b = "12345";
    Solution theSolution;
    string result = theSolution.mergeAlternately(a, b);
}