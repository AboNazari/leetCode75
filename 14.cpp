#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {

        int sum = 0;
        int size = nums.size();

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;
        for (int j = k; j < size; j++) {
            sum += nums[j] - nums[j - k];
            maxSum = max(sum, maxSum);
        }

        return static_cast<double>(maxSum) / k;
    }

};


int main() {

    Solution solution;
    int k = 4;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double res = solution.findMaxAverage(nums, k);
    cout << res;

    return 0;
}