#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int right = 0;
        int left = 0;
        int max_len = 0;
        int zero_count = 0;
        int size = nums.size();
        while (right < size) {
            if (nums[right] == 0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};


int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution solution;
    int res = solution.longestOnes(nums, k);

    cout << res;
    return 0;
}