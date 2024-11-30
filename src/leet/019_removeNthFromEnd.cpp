

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new  ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

void printListNode( ListNode *head){
    ListNode* current = head;
    while (current!= nullptr)
    {
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
    
}

// 主程序
int main() {

    int a;
    ListNode* head =nullptr;
    ListNode* tail =nullptr;
    while (cin >>a)
    {
        ListNode* newNode = new ListNode(a);
        if(head ==nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        if(getchar() == '\n'){
            break;
        }
    }
    printListNode(head);
    Solution s;
    s.removeNthFromEnd(head,2);
    

    return 0;
}