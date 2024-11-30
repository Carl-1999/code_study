/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com  
* @Data     : 2023-06-05 19:18
*
*/


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
   // 暴力解法 时间复杂度：O(n^2)
   // 空间复杂度：O(1)
   // int removeElement(vector<int>& nums, int val) {
   //    int len = nums.size();
   //    for(int i = 0;i<len;i++)
   //    {
   //       if(nums[i]==val)
   //       {
   //          for(int j =i+1;j<len;j++)
   //          {
   //             nums[j-1]=nums[j];
   //          }
   //          // 加一次减一次
   //          i--;
   //          len--;
   //       }
   //    }
   //    return len;
   // }
   // 快指针获取新数组中的元素，满指针获取新数组中更新位置
   int removeElement(vector<int>& nums, int val) {
      int slowIndex = 0;
      for(int fastIndex = 0;fastIndex<nums.size();fastIndex++){
         if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
      }
      return slowIndex;
   }
};

int main(int argc, char** argv)
{
   vector<int>v1 = {0,1,2,3,3,0,4,2};
   Solution solution;
   int a = solution.removeElement(v1,2);
   cout<<a<<endl;
   return 0;
}
