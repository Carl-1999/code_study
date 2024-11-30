#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

        // 提取高度数组，找高度的 LIS
        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            height[i] = envelopes[i][1];
        }

        return lengthOfLIS(height);
    }

private:
    // 返回 nums 中 LIS 的长度
    // int lengthOfLIS(vector<int>& nums) {
    //     int piles = 0;
    //     int n = nums.size();
    //     vector<int> top(n);
    //     for (int i = 0; i < n; i++) {
    //         int poker = nums[i];
    //         int left = 0, right = piles;
    //         // 二分查找插入位置
    //         while (left < right) {
    //             int mid = (left + right) / 2;
    //             if (top[mid] >= poker)
    //                 right = mid;
    //             else
    //                 left = mid + 1;
    //         }
    //         // 如果找不到合适的牌堆，新建一堆
    //         if (left == piles) piles++;
    //         top[left] = poker;
    //     }
    //     // 牌堆数就是 LIS 的长度
    //     return piles;
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
