#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int n, int oc, int cc, vector<char> &slate, vector<string> &result){
        if (oc == n && cc == oc){
            string sb;
            for( char c : slate ){
                sb.push_back(c);
            }
            result.push_back(sb);
            return;
        }

        if(oc < n){
            slate.push_back('(');
            helper(n, oc+1, cc, slate, result);
            slate.pop_back();
        }
        if(cc < oc){
            slate.push_back(')');
            helper(n, oc, cc+1, slate, result);
            slate.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> slate;
        helper(n, 0, 0, slate, result);
        return result;
    }
};



int main(){
    //string s = "sameep";
    int n = 3;
    Solution sol; // Fixed by creating an instance of Solution
    vector<string> res = sol.generateParenthesis(n); // Access through an instance, not directly via class
    for(auto str : res) { // Iterate correctly with references to avoid copies
    //    for (auto &str : vec) {
            cout << str << " "; // Correct output using '<<' instead of '>>'
     //   }
        //cout << endl; // Properly format output for clarity
    }
    return 0;
}