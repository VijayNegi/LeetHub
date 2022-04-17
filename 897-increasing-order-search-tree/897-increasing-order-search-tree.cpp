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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> stk;
        function<void(TreeNode*)> pushLefts = [&](TreeNode* node)
        {
            while(node)
            {
                stk.push_back(node);
                node = node->left;
            }
        };
        pushLefts(root);
        TreeNode dummy;
        TreeNode* curr = &dummy;
        while(stk.size())
        {
            TreeNode* node = stk.back();
            stk.pop_back();
            pushLefts(node->right);
            node->left = nullptr;
            curr->right = node;
            curr = node;
        }
        return dummy.right;
    }
};