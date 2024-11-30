#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(const vector<int>vec){
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int maxPlayTimes(vector<pair<int, int>> projects, int total_cost) {
    vector<int> dp(total_cost + 1, 0); // dp[j] 表示费用为 j 时的最大游玩次数

    for (auto& project : projects) {
        int price = project.first;  // 游玩单价
        int max_times = project.second; // 最大游玩次数

        // 对每个项目，逆序更新费用
        for (int j = total_cost; j >= price; --j) {
            for (int k = 1; k <= max_times && j >= k * price; ++k) {
                dp[j] = max(dp[j], dp[j - k * price] + k);
            }
        }
        printVector(dp);
    }

    return dp[total_cost];
}

int main() {
    vector<pair<int, int>> projects = {{10, 4}, {20, 3}, {15, 5}, {13, 1}};
    int total_cost = 100;

    int result = maxPlayTimes(projects, total_cost);
    cout << "最大游玩次数: " << result << endl;
    system("pause");
    return 0;
}
