#include "iostream"
#include "vector"


using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        //dp1 will store the minimum value of the left side;
        vector<int> dp1(n);
        dp1[0] = nums[0];
        for(int i = 1; i < n; i++){
            dp1[i] = min(dp1[i-1], nums[i]);
        }
        //dp2 will store the max value of the right side
        vector<int> dp2(n);
        dp2[n-1] = nums[n-1];
        for(int i = n-2; i>= 0; i--){
            dp2[i] = max(dp2[i+1], nums[i]);
        }
        for(int i = 1; i < n-1; i++){
            //check if there is min < num < max
            if(dp1[i-1] < nums[i] && nums[i] < dp2[i+1]){
                return true;
            }
        }
        return false;
    }
};


int main() {
    vector<int> nums = {1,5,0,4,1,3};
    Solution solution;
    bool res = solution.increasingTriplet(nums);
    cout << res << endl;
    return 0;
}