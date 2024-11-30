#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxP(vector<int>& nums){
    // f[i]表示以num[i]结尾的连续子数组乘积的最大值。
    if(nums.empty()) return 0;
    int n = nums.size();
    int max_P = nums[0];
    int min_P = nums[0];
    int result = nums[0];
    for(int i = 1;i<n;i++){
        if(nums[i]<0){
            swap(max_P,min_P);
        }
        max_P = max(nums[i],max_P*nums[i]);
        min_P = min(nums[i],min_P*nums[i]);
        result = max(result,max_P);
    }
    return result;

}


int main()
{
    vector<int>nums1 = {2,3,-2,4,5};
    vector<int>nums2 = {-2,-2,0,-1};
    int a = maxP(nums1);
    cout<<"a = "<<a<<endl;
    int b = maxP(nums2);
    cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
    system("pause");
    return 0;
}