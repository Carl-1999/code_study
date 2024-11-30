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
    //  dp[j] ��ʾ���� ��jԪʱ�����������������
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
����������
���ֳ���N����Ŀ��ÿ����Ŀ����Ҫ��Ǯ���棬��������������������
����һ������{100,4},[200,3]{150, 5}, {130,1}������{100,4},100Ϊ��Ŀ���浥�ۣ�4Ϊ����������
����Ƴ���:������������������������������ͬ��Ŀ����
�ظ�����
����:С��������1000Ԫ,100*4+130*1+150*3=980Ԫ,����������Ϊ8
*/