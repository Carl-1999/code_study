#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int boxCount;
    // ��ȡ���ӵ�����
    cin >> boxCount;

    // ����һ����ά�������洢ÿ�����ӵĳ��ȡ���Ⱥ͸߶�
    vector<vector<int>> boxes(boxCount + 1, vector<int>(3));
    
    // ��ȡÿ�����ӵĳ�������
    for (int i = 1; i <= boxCount; ++i) {
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];  // ������ӵĳ� l, �� w, �� h
    }

    // �Ժ��ӽ����������Ȱ��ճ���������������ǿ�ȣ����Ǹ߶�
    sort(boxes.begin(), boxes.end());


    // ��ӡboxes�е�ÿ��ֵ
    for (int i = 0; i <= boxCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "boxes[" << i << "][" << j << "] = " << boxes[i][j] << endl;
        }
    }

    // ��̬�滮���飬���ڴ洢��ÿ��������Ϊ�ѵ�����ʱ�����ѵ��߶�
    vector<int> maxHeight(boxCount + 1, 0);

    // ��̬�滮������ѵ��߶�
    for (int i = 1; i <= boxCount; ++i) {
        // ����֮ǰ�ĺ��ӣ�Ѱ���ܷ��ڵ�ǰ��������ĺ���
        for (int j = 0; j < i; ++j) {
            // �жϵ�ǰ�����Ƿ���Զѵ���ǰһ������֮�ϣ��������߶�Ҫ��ǰһ�����Ӵ�
            if (boxes[j][0] < boxes[i][0] && boxes[j][1] < boxes[i][1] && boxes[j][2] < boxes[i][2]) {
                // ���µ�ǰ������Ϊ����ʱ�����ѵ��߶�
                maxHeight[i] = max(maxHeight[j] + boxes[i][2], maxHeight[i]);
            }
        }
    }

    // ������п��ܶѵ��е����߶�
    cout << *max_element(maxHeight.begin(), maxHeight.end()) << endl;

    return 0;
}
