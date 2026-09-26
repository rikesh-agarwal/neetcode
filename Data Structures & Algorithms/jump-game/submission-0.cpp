class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;
        for(int i=0;i<nums.size();i++) {
            if(i>maxIdx) return false;
            maxIdx=max(i+nums[i], maxIdx);
        }

        if(maxIdx<nums.size()-1) return false;
        return true;
    }
};
