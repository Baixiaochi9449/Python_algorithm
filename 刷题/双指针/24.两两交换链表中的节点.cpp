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
        ListNode* swapPairs(ListNode* head) {
            //每换完一次，就往前走2个。 能否直接使用swap?
            if(head==nullptr) return nullptr;
            if(head->next==nullptr) return head;
            ListNode* dummy = new ListNode(0);
            dummy->next=head;
            ListNode* pre=dummy;
            ListNode* first=dummy->next;
            ListNode* second=first->next;
            while(second!=nullptr){
                // swap(first,second);
                //swap操作
                pre->next=second;
                ListNode* temp=first;
                first->next=second->next;
                second->next=temp;
                temp=first;
                first=second;
                second=temp;
    
                first=first->next->next;
                if(first==nullptr || first->next==nullptr) break;
                pre=pre->next->next;
                second=first->next;
            }
            return dummy->next;
        }
    };