#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> result; // 收集符合条件的路径
vector<int> path; // 1节点到终点的路径

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j<i;j++){
                if (nums[j] < nums[i]) { // 如果要求非严格递增，将 '<' 改为 '<='
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    vector<int> nums;
    int num;
    while(cin >> num) {
        nums.push_back(num);
        // 读到换行符，终止循环
        if(getchar() == '\n') {
            break;
        }
    }
    // 验证是否读入成功
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution s;
    int a = 0;
    a = s.lengthOfLIS(nums);
    cout<< a<<endl;

}
