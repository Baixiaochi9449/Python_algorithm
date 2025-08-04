/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head==nullptr) return nullptr;
            //删除倒数第n个，首先要找到倒数第n+1个
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* p1 = dummy;
            for(int i=0;i<n+1;i++){
                p1=p1->next;
            }
            ListNode* p2=dummy;
            while(p1!=nullptr){
                p1=p1->next;
                p2=p2->next;
            }
            //此时p2指向的是倒数第n+1个结点。
            p2->next=p2->next->next; //操纵原链表已经改变
            return dummy->next;
        }
    };