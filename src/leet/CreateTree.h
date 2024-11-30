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

// ����������
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
        
        // �������ӽڵ�
        if (i < vec.size() && vec[i] != INT_MAX) {
            cur->left = new TreeNode(vec[i]);
            que.push(cur->left);
        }
        i++;
        
        // �������ӽڵ�
        if (i < vec.size() && vec[i] != INT_MAX) {
            cur->right = new TreeNode(vec[i]);
            que.push(cur->right);
        }
        i++;
    }
    
    return root;
}

// �ݹ�ɾ���������ڵ㣬��ֹ�ڴ�й©
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


// ͨ�õĴ�ӡ���麯��
template <typename T>
void printArray(const vector<T>& arr, const string& message = "Array contents:") {
    cout << message << endl;
    for (const auto& element : arr) {
        cout << element << endl;
    }
}

