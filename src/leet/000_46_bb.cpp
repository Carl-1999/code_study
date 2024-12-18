// 一维dp数组实现
#include <iostream>
#include <vector>
using namespace std;


void printVector(const vector<int>vec){
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // 读取 M 和 N
    int M, N;
    cin >> M >> N;

    vector<int> costs(M);
    vector<int> values(M);




    // for (int i = 0; i < M; i++) {
    //     cin >> costs[i];
    // }
    // for (int j = 0; j < M; j++) {
    //     cin >> values[j];
    // }
    // N 背包空间
    costs = {2, 2, 3, 1, 5, 2};
    values = {2, 3, 1, 5, 4, 3};
    // 创建一个动态规划数组dp，初始值为0
    vector<int> dp(N + 1, 0);

    // 外层循环遍历每个类型的研究材料

    // dp[j]为 容量为j的背包所背的最大价值。
    for (int i = 0; i < M; ++i)
    {
        // 内层循环从 N 空间逐渐减少到当前研究材料所占空间
        for (int j = N; j >= costs[i]; --j)
        {
            // 考虑当前研究材料选择和不选择的情况，选择最大值
            dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
        }
        printVector(dp);

    }

    // 输出dp[N]，即在给定 N 行李空间可以携带的研究材料最大价值
    cout << dp[N] << endl;
    system("pause");
    return 0;
}
