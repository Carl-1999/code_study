#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool fun(const string &world){
    if(world.size() < 3) return false;
    for(int i = 0; i<world.size()-2;i++){
        if(world[i] == world[i+1] && world[i+1] == world[i+2]){
            return true;
        }
    }
    return false;
}

int main() {
    string str;
    getline(cin,str);

    istringstream iss(str);
    string word;
    vector<string>result;
    while (iss >> word) {
        if(!fun(word)){
            result.push_back(word);
        }
    }
    for(int i = 0; i< result.size();i++){
        if(i > 0){
            cout<<" ";
        }
        cout<<result[i];
    }
    cout<<endl;

    return 0;
}