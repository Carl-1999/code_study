#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // 假设树最多有100000个结点
vector<int> tree[MAXN];  // 存储树的邻接表
int subtree_size[MAXN];  // 记录每个节点的子树大小

// 深度优先搜索计算每个节点的子树大小
void dfs(int node, int parent) {
    subtree_size[node] = 1;  // 当前节点自身的大小
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtree_size[node] += subtree_size[neighbor]; // 子树大小累加
        }
    }
}

int main() {
    int T;
    cin >> T;  // 读取测试组数
    while (T--) {
        int n, K;
        cin >> n >> K;
        
        // 初始化每次测试的数据
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();  // 清空上一组的树数据
        }

        // 读取树的边
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // 从根节点1开始DFS，计算每个节点的子树大小
        dfs(1, -1);

        // 收集每个子树的大小
        vector<int> sizes;
        for (int i = 1; i <= n; ++i) {
            sizes.push_back(subtree_size[i]);
        }

        // 按照子树大小从大到小排序
        sort(sizes.rbegin(), sizes.rend());

        // 计算最少操作次数
        int current_score = 0;
        int operations = 0;
        for (int size : sizes) {
            current_score += size;
            operations++;
            if (current_score >= K) {
                cout << operations << endl;
                break;
            }
        }

        // 如果遍历完所有子树仍然无法达到K分
        if (current_score < K) {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
