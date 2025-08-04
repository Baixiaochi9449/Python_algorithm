/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //一直遍历一遍，遍历过的就存到set里，如果出现过了，就说明有环
 class Solution {
    public:
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> num;
            ListNode* node=head;
            while(node!=nullptr){
                if(num.count(node)) return true;
                num.insert(node);
                node=node->next;
            }
            return false;
        }
    };