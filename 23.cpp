#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        unordered_map<string, int> rowCount, colCount;
        int n = grid.size(); // Assuming a square grid
        int pairsCount = 0;

        // Loop through rows to generate row hashes
        for (int i = 0; i < n; ++i) {
            string rowHash = "";
            for (int j = 0; j < n; ++j) {
                rowHash += to_string(grid[i][j]) + ",";
            }
            rowCount[rowHash]++;
        }

        // Loop through columns to generate column hashes
        for (int j = 0; j < n; ++j) {
            string colHash = "";
            for (int i = 0; i < n; ++i) {
                colHash += to_string(grid[i][j]) + ",";
            }
            colCount[colHash]++;
        }

        // Count matching pairs
        for (const auto& rowEntry : rowCount) {
            string hash = rowEntry.first; // The hash of the row
            int rowOccurrences = rowEntry.second; // Number of rows with this hash
            if (colCount.find(hash) != colCount.end()) {
                int colOccurrences = colCount[hash]; // Number of cols with this hash
                pairsCount += rowOccurrences * colOccurrences; // Multiply occurrences for matching hashes
            }
        }

        return pairsCount;
    }
};


int main() {

    Solution solution;
    vector<vector<int>> grid = {
            {3,2,1},
            {1,7,6},
            {2,7,7}
    };

    cout << "Number of matching row and column pairs: " << solution.equalPairs(grid) << endl;
    return 0;
}