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

// 反转链表函数
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next; // 暂存下一个节点
        current->next = prev; // 当前节点的 next 指向前一个节点
        
        prev = current; // 移动 prev 指针
        current = nextNode; // 移动 current 指针
    }
    return prev; // 返回新的头节点
}

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

    // 反转链表
    ListNode* reversedHead = reverseList(head);

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