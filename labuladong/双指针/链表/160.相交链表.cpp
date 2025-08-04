/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* p1=headA;
            ListNode* p2=headB;
            while(p1!=p2){   
                if(p1==nullptr){
                    p1=headB;
                }
                else p1=p1->next;
                if(p2==nullptr){
                    p2=headA;
                }
                else p2=p2->next;
            }
            //反正总会相等的，因为他们走的距离是一样的，最后肯定会到nullptr
            return p1;
        }
    };