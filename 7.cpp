#include "iostream"
#include "vector"

using namespace std;

// recursive solution o(n**2)
//class Solution {
//public:
//    int count = 0;
//    vector<int> output;
//
//    vector<int> productExceptSelf(vector<int> &nums) {
//        int mult = 1;
//        if (count == nums.size()) {
//            return output;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (count != i) {
//                mult = mult * nums[i];
//            } else {
//                mult = mult * 1;
//            }
//        }
//
//        output.push_back(mult);
//        count++;
//        productExceptSelf(nums);
//
//        return output;
//    }
//};


// left to right solution o(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> output(n, 1); // Initialize output array with 1s

        int left = 1;
        for (int i = 0; i < n; i++) {
            output[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};


int main() {
    vector<int> nums = {2, 2, 3, 4};
    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    for (int i: result) {
        cout << i << endl;
    }
    return 0;
}