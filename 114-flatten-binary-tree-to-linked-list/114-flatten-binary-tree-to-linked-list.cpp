/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(curr) {
            if(curr->right)
                stk.push(curr->right);
            curr->right = curr->left;
            curr->left = nullptr;
            if(!curr->right && stk.size()) {
                curr->right = stk.top();
                stk.pop();
            }
            curr = curr->right;
        }
    }
};