#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result(nums.size(),0);
        int k = nums.size() - 1;
        
        for (int i = 0,j = nums.size()-1; i<=j;)
        {
            if(nums[i]*nums[i]<nums[j]*nums[j])
            {
                result[k--]=nums[j]*nums[j];
                j--;
            }
            else{
                result[k--]=nums[i]*nums[i];
                i++;
            }
        }
        return result;
    }
};

int main(int argc, char** argv)
{
   vector<int>v1 = {-4,-1,0,3,10};
   Solution solution;
   
    solution.sortedSquares(v1);
    cout<<"hahaha"<<endl;
    return 0;
}
