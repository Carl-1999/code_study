/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-06-01 17:50
*
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int middle = left + (right-left)/2;
            if(nums[middle]<target)
            {
                left = middle+1;
            }else if (nums[middle]>target)
            {
                right = middle-1;
            }else 
            {
                return middle;
            }
        }
        return right+1;
    }

    // int searchInsert(vector<int>& nums, int target) {
    //     for(int i = 0;i<nums.size();i++)
    //     {
    //         if(nums[i]>=target)
    //         {
    //             return i;
    //         }
    //     }
    //     return nums.size();
    // }
    
};

int main(){
   vector<int>num1 = {-1,0,3,5,9,12};
   vector<int>num2;
   Solution s;
   cout <<"hahahah" << endl;
   int a = s.searchInsert(num1,13);
   cout <<a<< endl;
   
   return 0;
}
