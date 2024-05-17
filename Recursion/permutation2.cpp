// Two approaches -
// 1. using set to store individual ans, can be solved using arrays.
// 2. sort the input and check if next is same then don't consider that. just continue.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class permutation{
	void permuteHelper(vector<vector<int>>& result, vector<int> slate, int idx ){
	}
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> result;
		vector<int> slate;
		sort(nums.begin(),nums.end());
		permuteHelper(result, slate, 0);
		return result;	

	}
};
