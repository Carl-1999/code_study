#include <iostream>
#include<vector>
#include<string>

using namespace std;


// ��������ڵ�ṹ
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
    // ��ӡ����
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
        // �����µĽڵ�
        ListNode* newNode = new ListNode(a);
        
        if (list1 == nullptr) {
            // ��һ���ڵ�
            list1 = newNode;
            tail = newNode;
        } else {
            // ���뵽����ĩβ
            tail->next = newNode;
            tail = newNode;
        }
    }
    while (n--)
    {
        cin>>a;
        // �����µĽڵ�
        ListNode* newNode = new ListNode(a);
        
        if (list2 == nullptr) {
            // ��һ���ڵ�
            list2 = newNode;
            tail = newNode;
        } else {
            // ���뵽����ĩβ
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
