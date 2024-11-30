/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-05-26 10:07
*
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for ( i = 0; i < nums.size(); i++) //最差的情况遍历nums.size()-1次,即出现符合的情况在最后两位
        {
            for ( j = i+1; j < nums.size(); j++)
            {
                if(target-nums[i]==nums[j])
                    return {i,j};
            }
        }
        return {};
    }
};

int main(){
   vector<int>num1 = {2,7,11,15};
   vector<int>num2;
   Solution s;
   cout <<"hahahah" << endl;
   num2=s.twoSum(num1,26);
   cout <<num2[0]<< endl;
   cout <<num2[1]<< endl;
   
   return 0;
}
