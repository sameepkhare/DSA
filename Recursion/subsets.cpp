#include<vector>
#include<iostream>
#include<algorithm>

class solution{
    private:
        void helper(vector<int> nums, vector<vector<int>>& result, vector<int>& slate, int idx){
            if( idx >= nums.size()){
                result.push_back(slate);
                return;
            }
            // instead of this helper we can use for loop (based on choices) for(int i = j; i < nums.size(); i++))
            helper(nums, result, slate, i+1);

            slate.push_back(nums[i]);
            helper(nums, result, slate, i+1);           
            slate.pop_back();
        }
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            vector<vector<int>> result;
            vector<int> slate;
            helper(nums, result, slate, 0);
            return result;
        }
};

int main(){

}