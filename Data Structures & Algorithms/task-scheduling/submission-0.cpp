class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> q;  // We don't really need to store the character in queue. It doesn't matter. We only care about their frequency.
        stack<int> st;

        for(char ch: tasks) freq[ch-'A']++;
        for(int i=0; i<freq.size();i++) {
            if(freq[i]>0) q.push(freq[i]);
        }

        int ans=0;
        while(!q.empty()) {
            int cycle=n+1;
            int taskcount=0;
            while(!q.empty() && cycle--) {  // The idea is that we don't really need to push the element back into the queue immediately. We can wait umtil one cycle is over.
                int count=q.top();
                q.pop();

                if(--count>0) st.push(count);
                taskcount++;
            }

            while(!st.empty()) {
                q.push(st.top());
                st.pop();
            }

            int currcycle = n+1;
            if(q.empty()) currcycle=taskcount;
            ans=ans+currcycle;
        }

        return ans;
    }
};
