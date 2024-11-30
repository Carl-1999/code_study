#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int x : nums)
        {
            if(s.find(x) != s.end())
            {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};


int main(){

    Solution s;
    vector<int>a = {1,5,1,3,3,4,3,2,4,2};
    int b = s.containsDuplicate(a);
    cout<<"b = "<<b<<endl;

    system("pause");
}