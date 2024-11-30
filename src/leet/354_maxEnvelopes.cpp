#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // ������������У�������һ�����򰴸߶Ƚ�������
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

        // ��ȡ�߶����飬�Ҹ߶ȵ� LIS
        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            height[i] = envelopes[i][1];
        }

        return lengthOfLIS(height);
    }

private:
    // ���� nums �� LIS �ĳ���
    // int lengthOfLIS(vector<int>& nums) {
    //     int piles = 0;
    //     int n = nums.size();
    //     vector<int> top(n);
    //     for (int i = 0; i < n; i++) {
    //         int poker = nums[i];
    //         int left = 0, right = piles;
    //         // ���ֲ��Ҳ���λ��
    //         while (left < right) {
    //             int mid = (left + right) / 2;
    //             if (top[mid] >= poker)
    //                 right = mid;
    //             else
    //                 left = mid + 1;
    //         }
    //         // ����Ҳ������ʵ��ƶѣ��½�һ��
    //         if (left == piles) piles++;
    //         top[left] = poker;
    //     }
    //     // �ƶ������� LIS �ĳ���
    //     return piles;
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
