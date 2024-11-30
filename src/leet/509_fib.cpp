#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        return fib(N - 1) + fib(N - 2);
    }
};

int main(){

    Solution solution;
    vector<int>s = {1,0,2};
    vector<int>g = {1,3,4,5,2};
    int b = solution.fib(5);
    cout<<"b = "<<b<<endl;

    system("pause");
}