#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    void preorder(TreeNode *root,vector<int>&res)
    {
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }


    vector<int> preorderTraversal(TreeNode *root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }
};


int main(){

    
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);

    Solution s;
    vector<int>a = {1,NULL,2,3};
    vector<int>b = s.preorderTraversal(root);

    for(auto array: b) {
        std::cout << array << " ";
    }
    std::cout << std::endl;

    system("pause");
}