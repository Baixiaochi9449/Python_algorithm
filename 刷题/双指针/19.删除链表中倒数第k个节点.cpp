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
            //如何找到倒数第k个节点？
            //倒数第k个是 正数第 n-k+1个
            //一个指针从起点走，一个指针从第k个位置走，当p2走到末尾，走了 n-k步 。所以第一个指针走了n-k步，就走到了要删除的节点的位置
            //让第一个指针先走k步
            ListNode* dummy = new ListNode(0);
            dummy->next=head;
            ListNode* slow=dummy;
            ListNode* fast=dummy;
            for(int i=0;i<=n;i++){
                fast=fast->next;
            }
            while(fast!=nullptr){  //这个条件，是fast走到了最后一个节点的->next的位置， 所以slow才走到了要删除的节点的位置
                fast=fast->next; 
                slow=slow->next;   //按照原来的思路，slow其实是走到了要删除的节点的位置
            }
    
           //现在slow走到的位置才是要删除的节点的前一个位置
            slow->next = slow->next->next;
            // ListNode* ans=dummy->next;
            // delete dummy;
            return dummy->next;
    
        }
    };