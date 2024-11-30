#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price=prices[0],profit_Max=0;
        for(int i = 1;i<prices.size();i++)
        {
            if(buy_price>prices[i])
            {
                buy_price = prices[i];
            }else{
                int profit = prices[i] - buy_price;
                profit_Max = profit_Max>profit? profit_Max:profit;
            }
        }

        return profit_Max;
    }
};




int main(){

    
    Solution s;
    vector<int>a = {7,1,5,3,6,4};
    int b = s.maxProfit(a);
    cout<<"b = "<<b<<endl;

    system("pause");
}