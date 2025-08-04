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
 //需要一个优先级队列，每次把k个数组中的头结点放进去，就可以直接比较了，使用了一个头结点后，就再把这个数组中的下一个放进去
 class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {  //这个lists存储的也是head
            ListNode* dummy = new ListNode(-1);
            ListNode* p=dummy;
            auto cmp = [](ListNode* a,ListNode* b){
                return a->val>b->val;
            };
            priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
            //把k个结点放到队列
            for(ListNode* head : lists){
                if(head!=nullptr)  pq.push(head);
            }
            while(!pq.empty()){
                ListNode* node =pq.top();
                pq.pop();
                p->next = node;
                if(node->next!=nullptr){
                    pq.push(node->next);
                }
                p=p->next;
            }
            return dummy->next;
        }
    };