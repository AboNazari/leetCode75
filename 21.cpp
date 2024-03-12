#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> count;

        for( int i : arr){
            count[i]++;
        }

        unordered_set<int> occurrence;

        for( auto &it:count){
            occurrence.insert(it.second);
        }

        return count.size() == occurrence.size();

    }
};


int main() {
    vector<int> nums = {-3,0,1,-3,1,1,1,-3,10,0};
    Solution solution;
    bool res = solution.uniqueOccurrences(nums);

    cout << res;
    return 0;
}