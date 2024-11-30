#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 创建二叉树
TreeNode* createTree(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }
    
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(vec[0]);
    que.push(root);
    
    int i = 1;
    while (i < vec.size()) {
        TreeNode* cur = que.front();
        que.pop();
        
        // 处理左子节点
        if (i < vec.size() && vec[i] != INT_MAX) {
            cur->left = new TreeNode(vec[i]);
            que.push(cur->left);
        }
        i++;
        
        // 处理右子节点
        if (i < vec.size() && vec[i] != INT_MAX) {
            cur->right = new TreeNode(vec[i]);
            que.push(cur->right);
        }
        i++;
    }
    
    return root;
}

// 递归删除二叉树节点，防止内存泄漏
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


// 通用的打印数组函数
template <typename T>
void printArray(const vector<T>& arr, const string& message = "Array contents:") {
    cout << message << endl;
    for (const auto& element : arr) {
        cout << element << endl;
    }
}

