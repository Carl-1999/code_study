#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        
        for(int i = 0;i<=range;i++)
        {
            range = max((nums[i] + i),range);
            if(range > nums.size()-1)
            {
                return true;
            }
        }
        return false;
    }
};

int main(){

    Solution solution;
    vector<int>s = {3,0,8,2,0,0,1};
    vector<int>g = {1,2,7,10};
    int b = solution.canJump(s);
    cout<<"b = "<<b<<endl;

    system("pause");
}