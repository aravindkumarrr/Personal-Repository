int maxSubArray(vector<int>& nums) {
    int sum = nums[0], maxSum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        sum = max(sum + nums[i], nums[i]); // "Is it better to extend the current subarray or start new?"
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
