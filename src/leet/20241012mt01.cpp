#include <iostream>
using namespace std;

// 判断一个数字是否是好数
bool isGoodNumber(int num) {
    int sumOfDigits = 0;
    bool hasOddDigit = false;

    while (num > 0) {
        int digit = num % 10;
        sumOfDigits += digit;
        if (digit % 2 == 1) {
            hasOddDigit = true;
        }
        num /= 10;
    }

    // 数位和为偶数且包含至少一个奇数数位
    return (sumOfDigits % 2 == 0) && hasOddDigit;
}

int main() {
    int n;

    cin >> n;
    
    int countGoodNumbers = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (isGoodNumber(a)) {
            countGoodNumbers++;
        }
    }
    
    cout << countGoodNumbers << endl;
    return 0;
}
