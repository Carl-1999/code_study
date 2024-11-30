#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// ���������滻���ʽ�еı���
string replaceVariables(const string& expression, const map<string, string>& replacements) {
    string result = expression;
    for (const auto& [key, value] : replacements) {
        size_t pos = 0;
        while ((pos = result.find(key, pos)) != string::npos) {
            result.replace(pos, key.length(), "'" + value + "'");
            pos += value.length() + 2; // �����滻���ַ�������
        }
    }
    return result;
}

// ���������ֶ������򵥵��߼����ʽ
bool evaluateExpression(const string& expression) {
    // �Ա��ʽ���м򵥵��ֶ�����
    // ������ʽֻ���� 'AND'��'OR'��'='��ֻ������򵥵ı��ʽ
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
    cin.ignore(); // ���Ի��з�

    vector<string> expressions(n);
    map<string, string> replacements;

    // ��ȡ���ʽ
    for (int i = 0; i < n; ++i) {
        getline(cin, expressions[i]);
    }

    // ��ȡ��ֵ��
    for (int i = 0; i < m; ++i) {
        string key, value;
        cin >> key >> value;
        replacements[key] = value;
    }

    // ����ÿ�����ʽ
    for (int i = 0; i < n; ++i) {
        // �滻���ʽ�еı���
        string modifiedExpression = replaceVariables(expressions[i], replacements);
        
        // �������ʽ
        bool isHealthy = evaluateExpression(modifiedExpression);

        // ��������0 ��ʾ������1 ��ʾ������
        cout << (isHealthy ? 0 : 1) << endl;
    }

    return 0;
}
