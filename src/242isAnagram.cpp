/*
*
* @Author   : Tianfeng Guo
* @Contact  : Guotf1999@163.com
* @Data     : 2023-05-28 19:47
* 有效的字母异位词
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i]-'a']++;
            cout<<s[i]<<'a'<<endl;
        }
        for (int i = 0; i < t.size(); i++)
        {
            record[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(record[i]!=0)
            return false;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    cout<<solution.isAnagram(s,t)<<endl;
    system("pause");
    return 0;
}
