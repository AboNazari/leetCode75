#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0; // Index to write the next element
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the current character
            chars[writeIndex++] = currentChar;

            // If count > 1, convert it to a string and write each digit
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[writeIndex++] = c;
                }
            }
        }

        // Resize chars to the new length
        return writeIndex; // The new length of the compressed array
    }
};


int main() {
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'c'};
    Solution solution;
    solution.compress(chars);
    for (char i: chars) {
        cout << i << endl;
    }
    return 0;
}
