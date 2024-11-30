#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result; // �ռ�����������·��
vector<int> path; // 1�ڵ㵽�յ��·��

void dfs (const vector<vector<int>>& graph, int x, int n) {
    // ��ǰ�����Ľڵ�x ����ڵ�n 
    if (x == n) { // �ҵ�����������һ��·��
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) { // �����ڵ�x���ӵ����нڵ�
        if (graph[x][i] == 1) { // �ҵ� x���ӵĽڵ�
            path.push_back(i); // �������Ľڵ���뵽·������
            dfs(graph, i, n); // ������һ��ݹ�
            path.pop_back(); // ���ݣ��������ڵ�
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m;

    // �ڵ��Ŵ�1��n���������� n+1 ��ô�������
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    while (m--) {
        cin >> s >> t;
        // ʹ���ڽӾ��� ��ʾ����ͼ��1 ��ʾ s �� t ��������
        graph[s][t] = 1;
    }

    path.push_back(1); // ����ʲô·���Ѿ��Ǵ�0�ڵ����
    dfs(graph, 1, n); // ��ʼ����

    // ������
    if (result.size() == 0) cout << -1 << endl;
    for (const vector<int> &pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1]  << endl;
    }
}
