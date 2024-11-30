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