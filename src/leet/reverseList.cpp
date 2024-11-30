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

// ��ת������
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next; // �ݴ���һ���ڵ�
        current->next = prev; // ��ǰ�ڵ�� next ָ��ǰһ���ڵ�
        
        prev = current; // �ƶ� prev ָ��
        current = nextNode; // �ƶ� current ָ��
    }
    return prev; // �����µ�ͷ�ڵ�
}

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

    // ��ת����
    ListNode* reversedHead = reverseList(head);

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