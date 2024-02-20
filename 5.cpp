#include <vector>
#include "iostream"
#include "string"

using namespace std;


class Solution {
public:
    string reverseVowels(string &s) {
        vector<int> indices;
        vector<char> vowels;
        string letter = "aeiouAEIOU";
        int count = 1;
        for (int i = 0; i < s.size(); i++) {
            if (letter.find(s[i]) != string::npos) {
                indices.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        for (int j = 0; j < s.size(); j++) {
            if (letter.find(s[j]) != string::npos) {
                s[j] = vowels[vowels.size() - count];
                count++;
            }
        }
        return s;

    }
};


int main() {
    string s = "aye";

    Solution solution;

    string res = solution.reverseVowels(s);
    cout << res;

    return 0;
}