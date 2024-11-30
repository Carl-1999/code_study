#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        if (root->left == NULL && root->right== NULL) return 0;
        int leftValue = sumOfLeftLeaves(root->left);    // 左
        if (root->left && !root->left->left && !root->left->right) { // 左子树就是一个左叶子的情况
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);  // 右

        int sum = leftValue + rightValue;               // 中
        return sum;

    }
};

int main() {
    vector<int> input = {3, 5, 1};
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    int output = solution.sumOfLeftLeaves(root);

    cout<<output<<endl;

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
