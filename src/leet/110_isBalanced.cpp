#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
int main() {
    // vector<int> input = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    vector<int> input = {3, 5, 1};
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    int depth = solution.isBalanced(root);
    cout << "Max Depth: " << depth << endl;

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
