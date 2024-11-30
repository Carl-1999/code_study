/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-05-29 09:45
* 两个数组的交集
*/


#include <iostream>
#include <vector>
#include <unordered_set>
// #include "myUtilts.h"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>result_set;
        unordered_set<int>nums_set(nums1.begin(),nums1.end());
        for(int num :nums2)
        {
            if(nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(),result_set.end());
    }
};

void print_vector(vector<int>& v1){
    for(auto i :v1)
        cout<<i<<" ";
    cout<<endl;
}

int main(int argc, char** argv)
{
   vector<int>v1 = {1,2,2,1,3};
   vector<int>v2 = {1,2,5,4,3};
   vector<int>v3;
   Solution solution;
   v3 = solution.intersection(v1,v2);
   print_vector(v3);
   system("pause");
   return 0;
}
