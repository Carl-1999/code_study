#include <iostream>
#include<vector>
#include<string>

using namespace std;

// ��������ڵ�ṹ
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        int sum1 = 0,sum2 = 0;
        while(l1){
            int count = 1;
            sum1 = sum1 + count* l1->val;
            l1 = l1->next;
            count = count*10;
        }
        while(l2){
            int count = 1;
            sum2 = sum2 + count* l2->val;
            l2 = l2->next;
            count = count*10;
        }
        int sum = sum1 + sum2;
        while (sum)
        {
            sum
        }
    }
};

// ��ӡ����
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val<<" ";
        current = current->next;
    }
    cout << endl;
}

// ������
int main() {

    int a;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (cin>>a)
    {
        // �����µĽڵ�
        ListNode* newNode = new ListNode(a);
        
        if (head == nullptr) {
            // ��һ���ڵ�
            head = newNode;
            tail = newNode;
        } else {
            // ���뵽����ĩβ
            tail->next = newNode;
            tail = newNode;
        }
        if(getchar() == '\n'){
            break;
        }
    }

    // ��ӡԭʼ����
    cout << "ԭʼ����: ";
    printList(head);
    Solution s;

    // ��ת����
    ListNode* reversedHead = s.deleteDuplicates(head);

    // ��ӡ��ת�������
    cout << "��ת�������: ";
    // printList(reversedHead);
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val<<" ";
        current = current->next;
    }
    cout << endl;
    return 0;
}