#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candyVec(ratings.size(),1);
        for(int i = 1;i<ratings.size();i++)
        {
            if(ratings[i] > ratings[i-1]) candyVec[i] = candyVec[i-1] + 1;            
        }
        for(int i = ratings.size()-2;i>=0;i--)
        {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};

int main(){

    Solution solution;
    vector<int>s = {1,0,2};
    vector<int>g = {1,3,4,5,2};
    int b = solution.candy(g);
    cout<<"b = "<<b<<endl;

    system("pause");
}