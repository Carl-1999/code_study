#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ����������������ȡ�ַ����е��������ֲ��洢Ϊ����
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

    // ����K�ͻ���ַ���
    cin >> K;
    cin >> s;

    // ��ȡ�ַ����е���������
    vector<int> numbers = extractNumbers(s);

    // ����ȡ�����ֽ��н�������
    sort(numbers.begin(), numbers.end(), greater<int>());

    // �����K��������������������'N'
    if (K <= numbers.size()) {
        cout << numbers[K - 1] << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
