#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        vector<int> vals;
        for (int i: nums) {
            if (i != 0) {
                vals.push_back(i);
            }
        }
        for (int j: nums) {
            if (j == 0) {
                vals.push_back(j);
            }
        }
        nums = vals;
    }
};


int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(arr);

    for (int i: arr) {
        cout << i << endl;
    }

    return 0;
}