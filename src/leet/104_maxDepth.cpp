#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
public:
    // 计算节点的最大深度
    int getDepth(TreeNode* node, int depth = 1) {
        // 打印当前递归的节点信息
        if (node == nullptr) {
            cout << string(depth * 2, ' ') << "Null node, returning depth: " << depth << endl;
            return 0;
        }
        
        cout << string(depth, ' ') << "Visiting node with value: " << node->val << ", current depth: " << depth << endl;

        // 递归计算左右子树的深度
        int leftDepth = getDepth(node->left, depth + 1);
        int rightDepth = getDepth(node->right, depth + 1);

        // 计算当前节点的最大深度
        int currentDepth = max(leftDepth, rightDepth) + 1;
        cout << string(depth * 2, ' ') << "Node with value: " << node->val << ", max depth from this node: " << currentDepth << endl;

        return currentDepth;
    }

    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

int main() {
    // vector<int> input = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    vector<int> input = {3, 5, 1};
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Max Depth: " << depth << endl;

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
