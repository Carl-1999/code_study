#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // ��ǰ������Զ�����±�
        int ans = 0;            // ��¼�ߵ������
        int nextDistance = 0;   // ��һ��������Զ�����±�
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // ������һ��������Զ�����±�
            if (i == curDistance) {                         // ������ǰ������Զ�����±�
                ans++;                                  // ��Ҫ����һ��
                curDistance = nextDistance;             // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                if (nextDistance >= nums.size() - 1) break;  // ��ǰ������Զ�ൽ�Ｏ���յ㣬������ans++�����ˣ�ֱ�ӽ���
            }
        }
        return ans;
    }
};
int main(){

    Solution solution;
    vector<int>s = {3,0,3,2,0,0,1};
    vector<int>g = {1,2,7,10};
    int b = solution.jump(s);
    cout<<"b = "<<b<<endl;

    system("pause");
}