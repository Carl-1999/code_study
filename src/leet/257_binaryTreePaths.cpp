#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
private:
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        
        path += to_string(cur->val);

        // 打印当前节点值和路径
        cout << "Visiting node: " << cur->val << ", current path: " << path << endl;
        
        // 叶子节点，添加路径到结果中
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            cout << "Leaf node found. Completed path: " << path << endl;
            return;
        }

        // 处理左子节点
        if (cur->left) {
            path += "->";
            cout << "Going left from node: " << cur->val << ", path: " << path << endl;
            traversal(cur->left, path, result);
            path.pop_back();
            path.pop_back();
            // 回溯
            cout << "Backtracking from left of node: " << cur->val << ", path before popping: " << path << endl;
        }

        // 处理右子节点
        if (cur->right) {
            path += "->";
            cout << "Going right from node: " << cur->val << ", path: " << path << endl;
            traversal(cur->right, path, result);
            path.pop_back();
            path.pop_back();
            // 回溯
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
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    vector<string> output = solution.binaryTreePaths(root);

    // 打印所有路径
    cout << "All paths from root to leaf:" << endl;
    printArray(output);

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
