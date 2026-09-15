class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(edges.size()+1, 1);
        vector<int> rank(edges.size()+1);
        for(int i=0;i<root.size();i++) root[i]=i;

        for(auto edge: edges) {
            int a=find(edge[0], root);
            int b=find(edge[1], root);
            if(a==b) return vector<int> {edge[0], edge[1]};
            doUnion(a, b, root, rank);
        }

        return vector<int> {-1, -1};
    }

    void doUnion(int a, int b, vector<int>& root, vector<int>& rank) {
        int root_a=find(a, root);
        int root_b=find(b, root);

        if(rank[root_a]>rank[root_b]) {
            root[root_b]=root_a;
            rank[root_a]+=rank[root_b];
        } else {
            root[root_a]=root_b;
            rank[root_b]+=rank[root_a];
        }
    }

    int find(int node, vector<int>& root) {
        while(root[node]!=node) {
            root[node]=root[root[node]];
            node=root[node];
        }

        return root[node];
    }
};