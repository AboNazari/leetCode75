#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int count = 0;
        int count2=0;
        for (int i = 0; i < k; i++) {
            if (vowels.find(s[i]) != std::string::npos) {
                count++;
            }
        }
        count2 = count;
        for (int j = k; j < s.size(); j++) {
            if (vowels.find(s[j - k]) != std::string::npos ) {
                count2--;
            }
            if (vowels.find(s[j]) != string::npos) {
                count2++;
            }

            if(count2 > count){
                count = count2;
            }

        }

        return count;
    }
};


int main() {
    string s = "aeiou";
    int k=2;
    Solution solution;
    int res = solution.maxVowels(s,k);
    cout << res;
    return 0;
}


//            cout << s[j] <<endl;
//            cout << s[j-k] <<endl;
//            cout << count <<endl;