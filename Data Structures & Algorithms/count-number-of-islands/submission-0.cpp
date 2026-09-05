class Solution {
public:
    vector<int> dx={1, 0, -1, 0};
    vector<int> dy={0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    cout << i << " " << j << endl;
                    grid[i][j]='0';
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()) {
                if(grid[nx][ny]=='1') {
                    grid[nx][ny]='0';
                    dfs(grid, nx, ny);
                }
            }
        }

        return;
    }
};