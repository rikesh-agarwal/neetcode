class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int num: nums) {
            if(mp[num]==true) return true;
            mp[num]=true;
        }

        return false;
    }
};