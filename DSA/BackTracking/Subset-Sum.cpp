#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int>& nums, int target, int index, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    if (target < 0 || index == nums.size()) {
        return;
    }

    current.push_back(nums[index]);
    findSubsets(nums, target - nums[index], index + 1, current, result);

    current.pop_back();

    findSubsets(nums, target, index + 1, current, result);
}

int main() {
    vector<int> nums = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    
    vector<vector<int>> result;
    vector<int> current;

    findSubsets(nums, target, 0, current, result);

    cout << "Subsets summing to " << target << ":\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
