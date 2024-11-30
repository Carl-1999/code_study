#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// 函数用于替换表达式中的变量
string replaceVariables(const string& expression, const map<string, string>& replacements) {
    string result = expression;
    for (const auto& [key, value] : replacements) {
        size_t pos = 0;
        while ((pos = result.find(key, pos)) != string::npos) {
            result.replace(pos, key.length(), "'" + value + "'");
            pos += value.length() + 2; // 跳过替换的字符串长度
        }
    }
    return result;
}

// 函数用于手动评估简单的逻辑表达式
bool evaluateExpression(const string& expression) {
    // 对表达式进行简单的手动评估
    // 假设表达式只包含 'AND'、'OR'、'='，只评估最简单的表达式
    stringstream ss(expression);
    string token;
    string left, op, right;
    bool result = true;

    while (ss >> token) {
        if (token == "AND") {
            result = result && (left == right);
        } else if (token == "OR") {
            result = result || (left == right);
        } else if (token == "=") {
            op = token;
        } else if (op.empty()) {
            left = token;
        } else {
            right = token;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); // 忽略换行符

    vector<string> expressions(n);
    map<string, string> replacements;

    // 读取表达式
    for (int i = 0; i < n; ++i) {
        getline(cin, expressions[i]);
    }

    // 读取键值对
    for (int i = 0; i < m; ++i) {
        string key, value;
        cin >> key >> value;
        replacements[key] = value;
    }

    // 处理每个表达式
    for (int i = 0; i < n; ++i) {
        // 替换表达式中的变量
        string modifiedExpression = replaceVariables(expressions[i], replacements);
        
        // 评估表达式
        bool isHealthy = evaluateExpression(modifiedExpression);

        // 输出结果：0 表示健康，1 表示不健康
        cout << (isHealthy ? 0 : 1) << endl;
    }

    return 0;
}
