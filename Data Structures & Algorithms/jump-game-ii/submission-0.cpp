class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        // For each index i, record i as a possible predecessor of the farthest position it can reach.
        vector<int> track(n, INT_MAX);
        track[0]=0;

        for(int i=0;i<nums.size();i++) {
            int idx=min(n-1, i+nums[i]);
            track[idx]=min(track[idx], i);  
        }

        // If i can reach position x, it can also reach every position before x.
        for(int i=n-2;i>=0;i--) track[i]=min(track[i+1], track[i]);

        // Walk backwards through predecessors to count the number of jumps.
        int idx=n-1, ans=0;
        while(idx>0) {
            idx=track[idx];
            ans++;
        }

        return ans;
    }
};