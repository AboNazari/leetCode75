#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;
        if (n == 0) return true;
        int size = flowerbed.size();
        for (int i = 0; i < size && count < n; i++) {
            bool leftIsEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightIsEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
            if (flowerbed[i] == 0 && leftIsEmpty && rightIsEmpty) {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;

    }
};

int main() {
    vector<int> flowerbed = {0};
    int n = 1;
    Solution solution;
    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << result;
    return 0;
}