#include "string"
#include "iostream"


using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res = "";
        int size;
        if (str1.size() > str2.size()) {
            size = str1.size();
        } else {
            size = str2.size();
        }

        for (int a = 0; a < size; a++) {
            if(str1[a] == res[0] && str1[a+1] == res[1]){
                break;
            }
            if(str1[a] == str2[a] ){
                res.push_back(str1[a]);
            }

        }

        cout << res;
        return res;
    }
};


int main(){
    string a = "ABCDEABCDEABCDEABCDE";
    string b = "ABCDEABCDE";

    Solution solution;
    solution.gcdOfStrings(a,b);
}