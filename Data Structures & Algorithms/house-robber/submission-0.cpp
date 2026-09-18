class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return dp(nums, 0, mem);
    }

    int dp(vector<int>& nums, int idx, vector<int>& mem) {
        if(idx==nums.size()-1) return nums[idx];
        if(idx==nums.size()-2) return max(nums[idx], nums[idx+1]);
        if(mem[idx]>-1) return mem[idx];

        return mem[idx] = max(nums[idx]+dp(nums, idx+2, mem), dp(nums, idx+1, mem));
    }
};
