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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = dummy;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                while (cur->next && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
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