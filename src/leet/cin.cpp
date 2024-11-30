// #include <iostream>
// using namespace std;
// int main(){
//     int sum, a;
//     sum = 0;
//     while(cin >> a){
//         sum += a;
//         if(getchar() == '\n'){
//             cout << sum << endl;
//             sum = 0;
//         }
//     }
// }


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
// #include<sstream>
using namespace std;
int main(){
    string line;
 
    while(getline(cin, line)){
        stringstream ss(line);
        string str;
        vector<string> strs;
        while(getline(ss, str, ' ')){
            strs.push_back(str);
        }
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs.size() - 1; i++){
            cout << strs[i] << " ";
        }
        cout << strs[strs.size() - 1] << endl;
    }
}