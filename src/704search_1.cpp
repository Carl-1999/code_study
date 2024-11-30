/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-05-31 10:53
* 第一种写法，我们定义 target 是在一个在左闭右闭的区间里，也就是[left, right] （这个很重要非常重要）。
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1; //定义target在左闭右闭的区间里，[left,right]
        while (left<=right)
        {
            int middle = left+(right-left)/2;
            if (nums[middle]>target)
            {
                right = middle-1;
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
