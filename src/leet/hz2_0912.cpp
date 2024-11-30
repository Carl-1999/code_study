#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int boxCount;
    // 读取盒子的数量
    cin >> boxCount;

    // 创建一个二维数组来存储每个盒子的长度、宽度和高度
    vector<vector<int>> boxes(boxCount + 1, vector<int>(3));
    
    // 读取每个盒子的长、宽、高
    for (int i = 1; i <= boxCount; ++i) {
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];  // 输入盒子的长 l, 宽 w, 高 h
    }

    // 对盒子进行排序，首先按照长度升序排序，其次是宽度，再是高度
    sort(boxes.begin(), boxes.end());


    // 打印boxes中的每个值
    for (int i = 0; i <= boxCount; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "boxes[" << i << "][" << j << "] = " << boxes[i][j] << endl;
        }
    }

    // 动态规划数组，用于存储当每个盒子作为堆叠顶部时的最大堆叠高度
    vector<int> maxHeight(boxCount + 1, 0);

    // 动态规划求解最大堆叠高度
    for (int i = 1; i <= boxCount; ++i) {
        // 遍历之前的盒子，寻找能放在当前盒子下面的盒子
        for (int j = 0; j < i; ++j) {
            // 判断当前盒子是否可以堆叠在前一个盒子之上（长、宽、高都要比前一个盒子大）
            if (boxes[j][0] < boxes[i][0] && boxes[j][1] < boxes[i][1] && boxes[j][2] < boxes[i][2]) {
                // 更新当前盒子作为顶部时的最大堆叠高度
                maxHeight[i] = max(maxHeight[j] + boxes[i][2], maxHeight[i]);
            }
        }
    }

    // 输出所有可能堆叠中的最大高度
    cout << *max_element(maxHeight.begin(), maxHeight.end()) << endl;

    return 0;
}
