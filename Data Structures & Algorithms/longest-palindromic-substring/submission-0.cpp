class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        vector<int> ans = {0,0};
        
        for(int i=0;i<s.size();i++) dp[i][i]=true;
        for(int i=0;i<s.size()-1;i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1] = true;
                ans={i, i+1};
            }
        }

        for(int diff=2;diff<n;diff++) {
            for(int i=0;i<n-diff;i++) {
                int j=i+diff;
                if(s[i]==s[j] && dp[i+1][j-1]==true) {
                    dp[i][j]=true;
                    ans = {i, j};
                }
            }
        }

        return s.substr(ans[0], ans[1]-ans[0]+1);
    }
};