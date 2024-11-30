#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 辅助函数，用于提取字符串中的所有数字并存储为整数
vector<int> extractNumbers(const string &s) {
    vector<int> numbers;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            numbers.push_back(num);
        }
    }
    return numbers;
}

int main() {
    int K;
    string s;

    // 输入K和混合字符串
    cin >> K;
    cin >> s;

    // 提取字符串中的所有数字
    vector<int> numbers = extractNumbers(s);

    // 对提取的数字进行降序排序
    sort(numbers.begin(), numbers.end(), greater<int>());

    // 输出第K个数，如果不存在则输出'N'
    if (K <= numbers.size()) {
        cout << numbers[K - 1] << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
