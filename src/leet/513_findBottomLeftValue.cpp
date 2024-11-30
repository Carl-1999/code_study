#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
public:
    int maxDepth = INT_MIN;
    int result = -1;
    void dfs(TreeNode* root,int depth){
        if(root->left == nullptr && root->right == nullptr){
            maxDepth  = depth > INT_MIN ? depth : INT_MIN;
            result = root->val;
            return;
        }
        
        if(root->left){
            depth++;
            dfs(root->left,depth);
            depth--;
        }
        if(root->right){
            depth++;
            dfs(root->right,depth);
            depth--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return result;
    }
};
int main() {
    vector<int> input = {1,2,3,4,INT_MAX,5,6,INT_MAX,INT_MAX,7};
    TreeNode* root = createTree(input); // 构建树

    Solution solution;
    int output = solution.findBottomLeftValue(root);

    cout<<output<<endl;

    // 释放树的内存
    deleteTree(root); // 假设你在 CreateTree.h 中有 deleteTree 函数来释放树的内存

    system("pause");
    return 0;
}
