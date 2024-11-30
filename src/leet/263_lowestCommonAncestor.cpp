// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "CreateTree.h"

using namespace std;


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root->val == q->val || root->val == p->val || root == NULL)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
        {
            return root;
        }

        if (left == NULL && right == NULL)
        {
            return right;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else // (left == NULL && right == NULL)
        {
            return NULL;
        }
    }
};


int main()
{
    vector<int> input = {3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4};
    TreeNode* root;
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);

    root = createTree(input);
    Solution solution = Solution();
    TreeNode* result = solution.lowestCommonAncestor(root, p, q);
    cout << result->val << endl;

    system("pause");
}
