#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false; // Correct palindrome check
            }
        }
        return true;
    }

    // Pass result and slate by reference to avoid copying large data structures
    void helper(string &s, int idx, vector<string> &slate,
                vector<vector<string>> &result) {
        if (idx == s.size()) {
            result.push_back(slate); // Correctly adding the complete partition
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) { // Correctly using the isPalindrome check
                slate.push_back(s.substr(idx, i - idx + 1)); // Fix substring logic to include correct range
                helper(s, i + 1, slate, result);
                slate.pop_back(); // Backtrack to try next potential partition
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> slate;
        helper(s, 0, slate, result); // Fixed by passing string, slate, and result by reference
        return result;
    }
};

int main(){
    string s = "sameep";
    Solution sol; // Fixed by creating an instance of Solution
    vector<vector<string>> res = sol.partition(s); // Access through an instance, not directly via class
    for(auto &vec : res) { // Iterate correctly with references to avoid copies
        for (auto &str : vec) {
            cout << "\"" <<str << "\"" << ", "; // Correct output using '<<' instead of '>>'
        }
        cout << endl; // Properly format output for clarity
    }
    return 0;
}
