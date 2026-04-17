#include <iostream>
#include <vector>
using namespace std; 
// At a store with exactly $target, and want to spend every single bit - no more, no less.
void findSubsets(vector<int>&nums, int target, int index, vector<int>&current, vector<vector<int>>& result){
    if(target == 0){
        // if you run out of EXACTLY how much you had -> success. Add this to solution.
        result.push_back(current);
        return;
    }
    if(target<0 || index==nums.size()){
        // If you went over your budget OR ran out of items to buy -> failure.
        return;
    }

    current.push_back(nums[index]); // Put the current item onto your cart.
    // For each item, you explore two parallel cases before moving on to next item: Include OR Exclude.
    findSubsets(nums,target-nums[index],index+1,current,result); // Include and move on to next item.
    // target - nums[index]: Means you spend on the current item (index), and move on to next item (index+1)
    current.pop_back();
    // We undo this and switch to the case where we exclude the item, by doing nothing with target and simply moving on to next item (index+1)
    findSubsets(nums, target, index+1, current, result);
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
