class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> mem(nums.size(), vector<int> (2, -1));
        return max(dp(nums, 1, 0, mem), nums[0]+dp(nums, 2, 1, mem));
    }

    int dp(vector<int>& nums, int idx, int firstRobbed, vector<vector<int>>& mem) {
        if(idx>=nums.size()) return 0;
        if(idx==nums.size()-1) {
            if(firstRobbed) return 0;
            else return nums[idx];
        }

        if(mem[idx][firstRobbed]>-1) return mem[idx][firstRobbed];
        return mem[idx][firstRobbed] =  max(nums[idx]+dp(nums, idx+2, firstRobbed, mem), 
                            dp(nums, idx+1, firstRobbed, mem));
    }
};