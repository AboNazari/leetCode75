#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int out = 0;

        int size = height.size();
        int len;
        int val;

        int i = 0;
        int j = size - 1;

        while (i < j) {
            len = j - i;

            int minVal = min(height[i], height[j]);
            val = minVal * len;
            out = max(val, out);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return out;
    }
};


int main() {
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution solution;
    int res = solution.maxArea(arr);

    cout << res << endl;
    return 0;
}