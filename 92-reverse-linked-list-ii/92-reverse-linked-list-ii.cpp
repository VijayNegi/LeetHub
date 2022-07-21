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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *lNode,*rNode,*curr;
        ListNode dummy(0,head);
        int idx=0;
        curr = &dummy;
        while(curr){
            if(idx== left-1) {
                lNode = curr;
                break;
            }
            curr = curr->next;
            ++idx;
        }
        while(curr){
            if(idx==right) {
                rNode = curr;
                break;
            }
            curr = curr->next;
            ++idx;
        }
        while(left!=right) {
            ListNode* temp = lNode->next;
            lNode->next = temp->next;
            temp->next = rNode->next;
            rNode->next = temp;
            ++left;
        }
        return dummy.next;
        
    }
};