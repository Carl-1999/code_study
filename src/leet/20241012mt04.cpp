#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

// �ж��Ƿ�Ϊ�����ĺ���
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// �������㷨Ѱ�����ƥ��
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

    vector<vector<int>> graph(n);  // �ڽӱ�洢ƥ��ͼ
    vector<vector<int>> gain(n, vector<int>(m, 0));  // ��¼ս������

    // ����ͼ�ıߺ�����
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool a_prime = is_prime(a[i]);
            bool b_prime = is_prime(b[j]);

            if (a_prime && b_prime) {
                gain[i][j] = a[i] + b[j];  // Ĭ����
            } else if (a_prime || b_prime) {
                gain[i][j] = max(a[i], b[j]);  // ������
            } else {
                gain[i][j] = b[j];  // ƽӹ��
            }

            graph[i].push_back(j);  // ��ӱ�
        }
    }

    vector<int> match(m, -1);  // ��¼С�ŵĳ���ƥ��Ķ���
    int total_gain = 0;

    // ����ƥ��ÿһ��С���ĳ���
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

    // �����������ƥ����
    cout << total_gain << endl;
    for (int i = 0; i < n; ++i) {
        int pet = -1;
        for (int j = 0; j < m; ++j) {
            if (match[j] == i) {
                pet = j + 1;  // ����ĳ����Ŵ�1��ʼ
                break;
            }
        }
        cout << pet << " ";
    }
    cout << endl;

    return 0;
}
