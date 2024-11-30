#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // �����������100000�����
vector<int> tree[MAXN];  // �洢�����ڽӱ�
int subtree_size[MAXN];  // ��¼ÿ���ڵ��������С

// ���������������ÿ���ڵ��������С
void dfs(int node, int parent) {
    subtree_size[node] = 1;  // ��ǰ�ڵ�����Ĵ�С
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtree_size[node] += subtree_size[neighbor]; // ������С�ۼ�
        }
    }
}

int main() {
    int T;
    cin >> T;  // ��ȡ��������
    while (T--) {
        int n, K;
        cin >> n >> K;
        
        // ��ʼ��ÿ�β��Ե�����
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();  // �����һ���������
        }

        // ��ȡ���ı�
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // �Ӹ��ڵ�1��ʼDFS������ÿ���ڵ��������С
        dfs(1, -1);

        // �ռ�ÿ�������Ĵ�С
        vector<int> sizes;
        for (int i = 1; i <= n; ++i) {
            sizes.push_back(subtree_size[i]);
        }

        // ����������С�Ӵ�С����
        sort(sizes.rbegin(), sizes.rend());

        // �������ٲ�������
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

        // �������������������Ȼ�޷��ﵽK��
        if (current_score < K) {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
