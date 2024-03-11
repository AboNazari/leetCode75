#include <iostream>
#include "vector"


using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sumRight;
        int sumLeft;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sumLeft = 0;
            sumRight = 0;

            for (int j = size - 1; j > i; j--) {
                sumRight += nums[j];
            }
            if (i == 0 && sumRight == 0) return 0;
            for (int x = 0; x < i; x++) {
                sumLeft += nums[x];
            }
            if (sumRight == sumLeft) return i;
        }


        return -1;
    }
};

int main() {
    vector<int> nums = {1,2,3};

    Solution solution;

    int res = solution.pivotIndex(nums);

    cout << res << endl;

    return 0;
}