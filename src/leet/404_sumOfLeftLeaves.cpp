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
        int leftValue = sumOfLeftLeaves(root->left);    // ��
        if (root->left && !root->left->left && !root->left->right) { // ����������һ����Ҷ�ӵ����
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);  // ��

        int sum = leftValue + rightValue;               // ��
        return sum;

    }
};

int main() {
    vector<int> input = {3, 5, 1};
    TreeNode* root = createTree(input); // ������

    Solution solution;
    int output = solution.sumOfLeftLeaves(root);

    cout<<output<<endl;

    // �ͷ������ڴ�
    deleteTree(root); // �������� CreateTree.h ���� deleteTree �������ͷ������ڴ�

    system("pause");
    return 0;
}
