#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> result; // �ռ�����������·��
vector<int> path; // 1�ڵ㵽�յ��·��

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j<i;j++){
                if (nums[j] < nums[i]) { // ���Ҫ����ϸ�������� '<' ��Ϊ '<='
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
        // �������з�����ֹѭ��
        if(getchar() == '\n') {
            break;
        }
    }
    // ��֤�Ƿ����ɹ�
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution s;
    int a = 0;
    a = s.lengthOfLIS(nums);
    cout<< a<<endl;

}
