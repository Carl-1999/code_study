#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
public:
    bool dfs(TreeNode* node,int count){
        if(!node->left && !node->right && count == 0) 
            return true;
        if(!node->left && !node->right)
            return false;
        if(node->left){
            count -= node->left->val;
            if(dfs(node->left,count)) return true;
            count += node->left->val;
        }
        if (node->right) { // 右
            count -= node->right->val;
        if (dfs(node->right, count)) return true;
            count += node->right->val;
        
        }
        return false;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return dfs(root,targetSum - root->val);
    }
};


int main() {
    vector<int> input = {5,4,8};
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    int output = solution.hasPathSum(root,13);

    cout<<output<<endl;

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
