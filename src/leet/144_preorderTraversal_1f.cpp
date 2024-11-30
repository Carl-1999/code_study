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

    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*>st;
        vector<int>result;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();                    
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);     
            if (node->left) st.push(node->left);     
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
    vector<int>b = s.preorderTraversal(root);

    for(auto array: b) {
        std::cout << array << " ";
    }
    std::cout << std::endl;

    system("pause");
}