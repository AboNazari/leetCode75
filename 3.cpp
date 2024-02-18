#include "iostream"
#include "vector"

using namespace std;



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        vector<bool> res(candies.size());
        bool big = true;
        for (int i = 0; i < candies.size(); i++) {
            for (int j = 0; j < candies.size(); j++) {
                if (candies[i] + extraCandies >= candies[j] && big) {
                    res[i] = true;
                } else {
                    big = false;
                    res[i] = false;
                }
            }
            big = true;
        }
        return res;
    }
};



int main() {

    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    Solution solution;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);

    for (int i = 0; i < candies.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
