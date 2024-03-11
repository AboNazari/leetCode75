#include "iostream"
#include "vector"


using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        vector<int> res;
        int val;
        int max = 0;
        res.push_back(0);

        for (int i = 0; i < gain.size(); i++) {
            val = gain[i] + res[i];
            res.push_back(val);
            cout << val << endl;
            if (val > max) {
                max = val;
            }
        }

        return max;
    }
};


int main() {

    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    Solution solution;
    int res = solution.largestAltitude(gain);
    cout << "res:  " << res;

    return 0;
}