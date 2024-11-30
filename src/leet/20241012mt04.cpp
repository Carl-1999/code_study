#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

// 判断是否为质数的函数
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// 匈牙利算法寻找最大匹配
bool dfs(int u, vector<vector<int>>& graph, vector<int>& match, vector<bool>& visited) {
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v], graph, match, visited)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    vector<vector<int>> graph(n);  // 邻接表存储匹配图
    vector<vector<int>> gain(n, vector<int>(m, 0));  // 记录战斗增益

    // 构建图的边和增益
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool a_prime = is_prime(a[i]);
            bool b_prime = is_prime(b[j]);

            if (a_prime && b_prime) {
                gain[i][j] = a[i] + b[j];  // 默契的
            } else if (a_prime || b_prime) {
                gain[i][j] = max(a[i], b[j]);  // 正常的
            } else {
                gain[i][j] = b[j];  // 平庸的
            }

            graph[i].push_back(j);  // 添加边
        }
    }

    vector<int> match(m, -1);  // 记录小团的宠物匹配的对象
    int total_gain = 0;

    // 尽量匹配每一个小美的宠物
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(m, false);
        if (dfs(i, graph, match, visited)) {
            for (int j = 0; j < m; ++j) {
                if (match[j] == i) {
                    total_gain += gain[i][j];
                    break;
                }
            }
        }
    }

    // 输出最大增益和匹配结果
    cout << total_gain << endl;
    for (int i = 0; i < n; ++i) {
        int pet = -1;
        for (int j = 0; j < m; ++j) {
            if (match[j] == i) {
                pet = j + 1;  // 输出的宠物编号从1开始
                break;
            }
        }
        cout << pet << " ";
    }
    cout << endl;

    return 0;
}
