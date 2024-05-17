#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        
    }
};



int main(){
    //string s = "sameep";
    int n = 3;
    Solution sol; // Fixed by creating an instance of Solution
    vector<string> res = sol.(n); // Access through an instance, not directly via class
    for(auto str : res) { // Iterate correctly with references to avoid copies
    //    for (auto &str : vec) {
            cout << str << " "; // Correct output using '<<' instead of '>>'
     //   }
        //cout << endl; // Properly format output for clarity
    }
    return 0;
}