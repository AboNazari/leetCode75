#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        unordered_map<char, int> fr1,fr2;
        for(char i: word1) fr1[i]++;
        for(char i: word2) fr2[i]++;

        if(fr1.size() != fr2.size()) return false;
        for(auto & itr : fr1){
            if(fr2.find(itr.first) == fr2.end()){
                return false;
            }
        }

        vector<int> count1, count2;
        for(auto & itr: fr1) count1.push_back(itr.second);
        for(auto & itr: fr2) count2.push_back(itr.second);

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};


int main() {
    string w1 = "abc";
    string w2 = "bca";
    Solution solution;
    bool res = solution.closeStrings(w1, w2);
    cout << res;
    return 0;
}