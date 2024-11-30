#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // ��ǰһ�Բ�ֵ
        int preDiff = 0; // ǰһ�Բ�ֵ
        int result = 1;
        for(int i = 0;i<nums.size()-1;i++)
        {
            curDiff = nums[i + 1] - nums[i];
            if((preDiff <=0 && curDiff > 0) || (preDiff >=0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff; // ע�����ֻ�ڰڶ��仯��ʱ�����prediff
            }
        }
        return result;
    }
    
};

int main(){

    Solution solution;
    vector<int>s = {1,2,3,7,6,5,4,9,2,5};
    vector<int>g = {1,2,7,10};
    int b = solution.wiggleMaxLength(s);
    cout<<"b = "<<b<<endl;

    system("pause");
}