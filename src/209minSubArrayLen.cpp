#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX; //最终的结果
        int sum = 0; //子序列的数值之和
        int subLength = 0; //子序列的长度
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j = i;j<nums.size();j++)
            {
                sum += nums[j];
                if(sum>=target){
                    subLength = j-i+1;
                    result = result<subLength ? result : subLength;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }

    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int result = INT32_MAX;
    //     int sum = 0; // 滑动窗口数值之和
    //     int i = 0; // 滑动窗口起始位置
    //     int subLength = 0; // 滑动窗口的长度
    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         sum +=nums[j];
    //         while (sum >= target)
    //         {
    //             subLength = j-i+1;
    //             result = result < subLength ? result : subLength;
    //             sum -= nums[i++];
    //         }
    //     }
    //     return result ==INT32_MAX ? 0 :result;
    // }
};

int main(int argc, char** argv)
{
    vector<int>v1 = {2,3,1,2,4,3};
    Solution solution;
    solution.minSubArrayLen(7,v1);
    cout<<"hahaha"<<INT32_MAX<<endl;
    return 0;
}
