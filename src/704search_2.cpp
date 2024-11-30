/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-05-31 10:53
* 如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) ，那么二分法的边界处理方式则截然不同。
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); //定义target在左闭右闭的区间里，[left,right]
        while (left<right)
        {
            int middle = left+(right-left)>>1;
            if (nums[middle]>target)
            {
                right = middle;
            }else if(nums[middle]<target)
            {
                left = middle+1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv)
{
   vector<int>v1 = {-1,0,3,5,9,12};
   Solution solution;
//    cout<<"hahaha"<<endl;
   cout<<solution.search(v1,13)<<endl;

   return 0;
}
