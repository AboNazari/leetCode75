#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word;
        bool start = false;
        vector<string> order;
        string result;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            char value = s[i];
            if (!std::isspace(value)) {
                start = true;
                word.push_back(value);
            }
            if (std::isspace(value) && start) {
                order.push_back(word);
                start = false;
                word = "";
            }
            if (i == size - 1 && !word.empty()) {
                order.push_back(word);
            }
        }

        int newSize = order.size();
        for (int j = newSize - 1; j >= 0; j--) {
            string val = order[j];
            if (j != newSize - 1) { // Check if it's not the first iteration in reverse
                result.push_back(' ');
            }
            result += val;
        }

        return result;
    }
};


int main() {

    string s = "     hello world  ";
    Solution solution;

    string res = solution.reverseWords(s);
    cout << "'";
    cout << res;
    cout << "'";
;
    return 0;
}