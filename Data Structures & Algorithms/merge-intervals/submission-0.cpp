class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevstart=-1, prevend=-1;

        vector<vector<int>> ans;
        for(auto interval:intervals) {
            int start=interval[0];
            int end=interval[1];

            if(start>prevend) {
                if(!(prevstart==-1 && prevend==-1)) {
                    ans.push_back(vector<int> {prevstart, prevend});
                }
                prevstart=start;
                prevend=end;
            } else if(start==prevstart || start<=prevend) {
                prevend=max(end, prevend);
            }
        }

        ans.push_back(vector<int> {prevstart, prevend});
        return ans;
    }
};

