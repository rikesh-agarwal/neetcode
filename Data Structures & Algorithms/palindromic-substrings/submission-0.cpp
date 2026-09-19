class Solution {
public:
    int countSubstrings(string s) {
        int ans=1;
        for(int i=0;i<s.size()-1;i++) {
            ans+=findpalindrome(i, i, s);
            ans+=findpalindrome(i, i+1, s);
        }

        return ans;
    }

    int findpalindrome(int l, int r, string s) {
        int count=0;
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            count++;
            l--;
            r++;
        }

        return count;
    }
};
