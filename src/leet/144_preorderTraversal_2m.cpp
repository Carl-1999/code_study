#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*>st;
        vector<int>result;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return result;
    }
};


int main(){

    
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    Solution s;
    vector<int>b = s.inorderTraversal(root);

    for(auto array: b) {
        std::cout << array << " ";
    }
    std::cout << std::endl;

    system("pause");
}