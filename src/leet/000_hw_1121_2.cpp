#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Project
{
    int cost;
    int max_times;
};

void printVector(const vector<int>vec){
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int maxPlay(int money,const vector<Project>pros){
    //  dp[j] 表示花费 回j元时可以游玩的最大次数。
    vector<int>dp(money + 1,0);
    for(const auto& pro :pros){
        for(int k = 1;k<=pro.max_times;++k){
            for(int j = money;j>=pro.cost;--j){
                dp[j] = max(dp[j],dp[j-pro.cost] + 1);

            }
            
        }
        printVector(dp);
    }
    return dp[money];

}

int main()
{
    int money = 105;

    vector<Project> projects = {{10,2},{20,3},{13,3},{15,5}};
    int result = maxPlay(money,projects);
    cout<<"result = "<<result<<endl;
    system("pause");
    return 0;
}


/*
最多游玩次数
游乐场有N个项目，每个项目都需要花钱游玩，并且有最多游玩次数限制
给定一个数组{100,4},[200,3]{150, 5}, {130,1}，对于{100,4},100为项目游玩单价，4为最大游玩次数
请设计程序:给定费用输出可以游玩的最大次数，相同项目可以
重复游玩
例如:小明手上有1000元,100*4+130*1+150*3=980元,最大游玩次数为8
*/