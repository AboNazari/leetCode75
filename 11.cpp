#include "iostream"

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0; // Position in t where we search for the next character of s
        for (int i = 0; i < s.size(); ++i) {
            pos = t.find(s[i], pos); // Find s[i] in t starting from pos
            if (pos == string::npos) {
                // If s[i] is not found, s is not a subsequence of t
                return false;
            }
            ++pos; // Move past the last found position to find subsequent characters
        }
        return true;
    }
};


int main() {
    string s = "abc";
    string t = "ahbgdc";

    Solution solution;
    bool res = solution.isSubsequence(s, t);
    cout << res;
    return 0;
}