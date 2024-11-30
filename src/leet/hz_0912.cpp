
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;  // 输入矩阵的行数 m 和列数 n

    // 读取矩阵并初始化距离矩阵和队列
    vector<vector<int>> matrix(m, vector<int>(n));  // 原始矩阵
    vector<vector<int>> dis(m, vector<int>(n, -1)); // 距离矩阵，初始化为 -1
    queue<pair<int, int>> q;  // 队列用于 BFS

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // 读入矩阵元素
            if (matrix[i][j] == 0) {  // 垃圾站 如果是零元素，将其坐标加入队列并初始化距离为 0
                q.push({i, j}); //存垃圾站的位置
                dis[i][j] = 0;  //垃圾站到自己的距离为0
            }
        }
    }

    int res = 0;  // 最终结果
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // 四个方向的偏移量数组

    // BFS 计算距离矩阵
    while (!q.empty()) {
        auto [i, j] = q.front();  // 取出队首元素
        q.pop();

        // 遍历四个方向
        for (auto dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];  // 新位置坐标
            // 检查新位置是否合法，且未访问过
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] != -1 && dis[ni][nj] == -1) {
                dis[ni][nj] = dis[i][j] + 1;  // 更新距离
                q.push({ni, nj});  // 将新位置加入队列
            }
        }
    }

    // 计算所有值为 1 的元素到最近的 0 元素的距离之和
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && dis[i][j] != -1) {  // 如果是值为 1 的元素且距离有效
                res += dis[i][j];  // 累加距离
            }
        }
    }

    cout << res << endl;  // 输出结果
}