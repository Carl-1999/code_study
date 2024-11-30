#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir[4][2] = {0,1,1,0,-1,0,0,-1};
void bfs(const vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
    queue<pair<int,int>>que;
    que.push({x,y});
    visited[x][y] = true;
    while(!que.empty()){
        pair<int,int>cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0;i<4;i++){
            int nx = curx + dir[i][0];
            int ny = cury + dir[i][1];
            if(nx<0||nx>=grid.size()|| ny<0||ny>=grid[0].size())
                continue;
            if(!visited[nx][ny] && grid[nx][ny] ==1){
                que.push({nx,ny});
                visited[nx][ny] = true;
            }
            
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                result++; // 遇到没访问过的陆地，+1
                bfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
            }
        }
    }
}