#include <iostream>
#include <vector>
#include <algorithm> // for max
#include "CreateTree.h"

using namespace std;

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // ��
        int rightDepth = getDepth(node->right);         // ��
                                                        // ��
        // ��һ��������Ϊ�գ��Ҳ�Ϊ�գ���ʱ��������͵�
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // ��һ��������Ϊ�գ���Ϊ�գ���ʱ��������͵�
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

int main() {
    vector<int> input = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    TreeNode* root = createTree(input); // ������

    Solution solution;
    int depth = solution.minDepth(root);
    cout << "Min Depth: " << depth << endl;

    // �ͷ������ڴ�
    deleteTree(root); // �������� CreateTree.h ���� deleteTree �������ͷ������ڴ�

    system("pause");
    return 0;
}
