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
    vector<int> nextLargerNodes(ListNode* head) {
        //我的想法就只能暴力了，如果按照数组的单调栈，如何倒序遍历呢
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* p1=head;
        vector<int> res;
        while(p1!=nullptr){
            ListNode* p2=p1->next;
            while(p2!=nullptr && p2->val<=p1->val){
                p2=p2->next;
            }
            if(p2==nullptr) res.push_back(0);
            else res.push_back(p2->val);
            p1=p1->next;
        }
        return res;
    }
};
