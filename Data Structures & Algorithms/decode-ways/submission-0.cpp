class Solution {
public:
    int numDecodings(string s) {
        vector<int> mem(s.size(), -1);
        return dp(s, 0, mem);
    }

    int dp(string s, int idx, vector<int>& mem) {
        if(idx>=s.size()) return 1;
        if(idx==s.size()-1) {
            if(s[idx]=='0') return mem[idx]=0;
            else return mem[idx]=1;
        }
        if(s[idx]=='0') return mem[idx]=0;

        if(mem[idx]>-1) return mem[idx];
        
        int num=s[idx]-'0';
        if(num>2) return mem[idx]=dp(s, idx+1, mem);
        else if(num==1) return mem[idx]=dp(s, idx+1, mem) + dp(s, idx+2, mem);
        else if(num==2) {
            int nextnum=s[idx+1]-'0';
            if(nextnum>6) return mem[idx]=dp(s, idx+1, mem);
            else return mem[idx]=dp(s, idx+1, mem) + dp(s, idx+2, mem);
        }

        return mem[idx]=0;
    }
};