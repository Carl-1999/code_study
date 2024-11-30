#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());

//         int result = 0;
//         for(int i = 0;i<nums.size();i++)
//         {
//             if(k > 0 && nums[i] < 0)
//             {
//                 nums[i] = -nums[i];
//                 k--;
//             }
//         }
//         sort(nums.begin(),nums.end());

//         while(k>0)
//         {
//             nums[0] = -nums[0];
//             k--;
//         }
//         for(int i = 0;i<nums.size();i++)
//         {
//             result += nums[i];
//         }
//         return result;
//     }
// };
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};

int main(){

    Solution solution;
    vector<int>s = {2,-3,-1,5,-4};
    vector<int>g = {1,2,7,10};
    int b = solution.largestSumAfterKNegations(s,5);
    cout<<"b = "<<b<<endl;

    system("pause");
}