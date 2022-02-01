/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> copyMap;
        Node Dummy1(0),Dummy2(0);
        Dummy1.next = head;
        
        Node* curr = &Dummy1;
        Node* newHead = &Dummy2;
        
        while(curr)
        {
            if(curr->random && copyMap[curr->random]==nullptr)
            {
                copyMap[curr->random] = new Node(curr->random->val);
            }
            newHead->random = copyMap[curr->random];
            if(curr->next && copyMap[curr->next]==nullptr)
            {
                copyMap[curr->next] = new Node(curr->next->val);
            }
            newHead->next = copyMap[curr->next];
            curr = curr->next;
            newHead = newHead->next;
        }
        return Dummy2.next;
    }
};