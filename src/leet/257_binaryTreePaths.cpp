#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
private:
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        
        path += to_string(cur->val);

        // ��ӡ��ǰ�ڵ�ֵ��·��
        cout << "Visiting node: " << cur->val << ", current path: " << path << endl;
        
        // Ҷ�ӽڵ㣬���·���������
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            cout << "Leaf node found. Completed path: " << path << endl;
            return;
        }

        // �������ӽڵ�
        if (cur->left) {
            path += "->";
            cout << "Going left from node: " << cur->val << ", path: " << path << endl;
            traversal(cur->left, path, result);
            path.pop_back();
            path.pop_back();
            // ����
            cout << "Backtracking from left of node: " << cur->val << ", path before popping: " << path << endl;
        }

        // �������ӽڵ�
        if (cur->right) {
            path += "->";
            cout << "Going right from node: " << cur->val << ", path: " << path << endl;
            traversal(cur->right, path, result);
            path.pop_back();
            path.pop_back();
            // ����
            cout << "Backtracking from right of node: " << cur->val << ", path before popping: " << path << endl;
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) return result;

        traversal(root, path, result);
        return result;
    }
};

int main() {
    vector<int> input = {3, 5, 1};
    TreeNode* root = createTree(input); // ������

    Solution solution;
    vector<string> output = solution.binaryTreePaths(root);

    // ��ӡ����·��
    cout << "All paths from root to leaf:" << endl;
    printArray(output);

    // �ͷ������ڴ�
    deleteTree(root); // �������� CreateTree.h ���� deleteTree �������ͷ������ڴ�

    system("pause");
    return 0;
}
