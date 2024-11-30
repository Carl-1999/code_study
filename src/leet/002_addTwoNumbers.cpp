#include <iostream>
#include<vector>
#include<string>

using namespace std;

// 定义链表节点结构
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

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val<<" ";
        current = current->next;
    }
    cout << endl;
}

// 主程序
int main() {

    int a;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (cin>>a)
    {
        // 创建新的节点
        ListNode* newNode = new ListNode(a);
        
        if (head == nullptr) {
            // 第一个节点
            head = newNode;
            tail = newNode;
        } else {
            // 插入到链表末尾
            tail->next = newNode;
            tail = newNode;
        }
        if(getchar() == '\n'){
            break;
        }
    }

    // 打印原始链表
    cout << "原始链表: ";
    printList(head);
    Solution s;

    // 反转链表
    ListNode* reversedHead = s.deleteDuplicates(head);

    // 打印反转后的链表
    cout << "反转后的链表: ";
    // printList(reversedHead);
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val<<" ";
        current = current->next;
    }
    cout << endl;
    return 0;
}