#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);

        for (int i: set1) {
            if (set2.find(i) == set2.end()) {
                res[0].push_back(i);
            }
        }
        for (int i: set2) {
            if (set1.find(i) == set1.end()) {
                res[1].push_back(i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {3, 2, 4};
    Solution solution;
    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    // Print the result for verification
    cout << "Unique to nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << "\nUnique to nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
