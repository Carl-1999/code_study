#include <iostream>
#include<vector>
#include<string>

using namespace std;


// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        
        ListNode* preHead = new ListNode(-1);

        ListNode* pre = preHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                pre->next = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        pre->next = list1 ==nullptr ? list2 : list1;
        return preHead->next;

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
};

int main() {
    int m,n;
    cin >> m>>n;

    int a;
    ListNode* list1 = nullptr;
    ListNode* tail = nullptr;
    ListNode* list2 = nullptr;

    while (m--)
    {
        cin>>a;
        // 创建新的节点
        ListNode* newNode = new ListNode(a);
        
        if (list1 == nullptr) {
            // 第一个节点
            list1 = newNode;
            tail = newNode;
        } else {
            // 插入到链表末尾
            tail->next = newNode;
            tail = newNode;
        }
    }
    while (n--)
    {
        cin>>a;
        // 创建新的节点
        ListNode* newNode = new ListNode(a);
        
        if (list2 == nullptr) {
            // 第一个节点
            list2 = newNode;
            tail = newNode;
        } else {
            // 插入到链表末尾
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution s;
    auto resutlt = s.mergeTwoLists(list1,list2);
    s.printList(resutlt);
    system("pause");
    return 0;
}
