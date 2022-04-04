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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *beg,*end,*curr;
        curr = beg= end = head;
        int n=1,i=1;
        while(curr)
        {
            if(i==k)
                beg = curr;
            if(i>k)
                end = end->next;
            ++i;
            curr= curr->next;
        }
        int val = beg->val;
        beg->val = end->val;
        end->val = val;
        return head;
    }
};