#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>>result;

static bool cmp(const vector<int>&a,const vector<int>&b){
    if(a[0] == b[0]) return a[1] <b[1];
    return a[0] >b[0];
}

int main() {
    

    return 0;
}