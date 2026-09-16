class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int toRot=0, m=grid.size(), n=grid[0].size();

        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) q.push({i, j});
                else if(grid[i][j]==1) toRot++;
            }
        }

        vector<int> dx={1, 0, -1, 0};
        vector<int> dy={0, 1, 0, -1};

        int time=0, rotten=0;
        while(!q.empty()) {
            if(rotten==toRot) return time;
            time++;

            int currsize=q.size();
            for(int i=0;i<currsize;i++) {
                auto top=q.front();
                q.pop();
                int x=top.first;
                int y=top.second;

                for(int j=0;j<4;j++) {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0 && nx<m && ny>=0 && ny<n) {
                        if(grid[nx][ny]==1) {
                            grid[nx][ny]=2;
                            q.push({nx, ny});
                            rotten++;
                        }
                    }
                }
            }
        }

        if(rotten!=toRot) return -1;
        return time;
    }
};