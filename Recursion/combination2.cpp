#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void findCombinations(vector<int>& candidates, int target, int start, vector<vector<int>>& result, vector<int>& combination) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < candidates.size() && target >= candidates[i]; ++i) {
        // Skip duplicates
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        combination.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], i + 1, result, combination);
        combination.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    findCombinations(candidates, target, 0, result, combination);
    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto results = combinationSum2(candidates, target);

    for (const auto& combination : results) {
        cout << "[";
        for (int num : combination) {
            cout << num << ",";
        }
        cout << "\b]\n";
    }

    return 0;
}