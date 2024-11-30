
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;  // ������������ m ������ n

    // ��ȡ���󲢳�ʼ���������Ͷ���
    vector<vector<int>> matrix(m, vector<int>(n));  // ԭʼ����
    vector<vector<int>> dis(m, vector<int>(n, -1)); // ������󣬳�ʼ��Ϊ -1
    queue<pair<int, int>> q;  // �������� BFS

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // �������Ԫ��
            if (matrix[i][j] == 0) {  // ����վ �������Ԫ�أ��������������в���ʼ������Ϊ 0
                q.push({i, j}); //������վ��λ��
                dis[i][j] = 0;  //����վ���Լ��ľ���Ϊ0
            }
        }
    }

    int res = 0;  // ���ս��
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // �ĸ������ƫ��������

    // BFS ����������
    while (!q.empty()) {
        auto [i, j] = q.front();  // ȡ������Ԫ��
        q.pop();

        // �����ĸ�����
        for (auto dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];  // ��λ������
            // �����λ���Ƿ�Ϸ�����δ���ʹ�
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] != -1 && dis[ni][nj] == -1) {
                dis[ni][nj] = dis[i][j] + 1;  // ���¾���
                q.push({ni, nj});  // ����λ�ü������
            }
        }
    }

    // ��������ֵΪ 1 ��Ԫ�ص������ 0 Ԫ�صľ���֮��
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && dis[i][j] != -1) {  // �����ֵΪ 1 ��Ԫ���Ҿ�����Ч
                res += dis[i][j];  // �ۼӾ���
            }
        }
    }

    cout << res << endl;  // ������
}