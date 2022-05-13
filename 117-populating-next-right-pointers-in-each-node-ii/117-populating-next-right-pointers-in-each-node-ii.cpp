/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr=root;
        Node* child=nullptr;
        Node* pre = nullptr;
        while(curr)
        {
            if(curr->left)
            {
                if(!pre)
                {
                    pre = child = curr->left;
                }
                else
                {
                    pre->next = curr->left;
                    pre = curr->left;
                }
            }
            if(curr->right)
            {
                if(!pre)
                {
                    pre = child = curr->right;
                }
                else
                {
                    pre->next = curr->right;
                    pre = curr->right;
                }
            }
            curr = curr->next;
            if(!curr)
            {
                curr = child;
                child = pre = nullptr;
            }
        }
        return root;
    }
};