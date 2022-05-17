/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result= nullptr;
        function<bool(TreeNode*,TreeNode*)> dfs = [&](TreeNode* node,TreeNode* clone){
            if(!node)
                return false;
            if(node == target)
            {
                result = clone;
                return true;
            }
            if(dfs(node->left,clone->left))
                return true;
            if(dfs(node->right,clone->right))
                return true;
            return false;
        };
        dfs(original,cloned);
            
        return result;
    }
};