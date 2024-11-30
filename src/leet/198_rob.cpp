#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            dp[i] = max(dp[i-2] +nums[i],dp[i - 1]);
        }
        return dp[nums.size() - 1];

    }
};




int main(){

    
    Solution s;
    vector<int>a = {2,7,5,3,1};
    int b = s.rob(a);
    cout<<"b = "<<b<<endl;

    system("pause");
}