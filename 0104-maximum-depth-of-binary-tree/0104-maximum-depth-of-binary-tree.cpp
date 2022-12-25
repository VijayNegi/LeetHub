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
    // old
    int maxDepth0(TreeNode* root) {
        
        int height = 0;
        function<void(TreeNode*,int)> traverse = [&](TreeNode* node,int h){
            if(!node)
                return;
            if(h>height)
                height = h;
            traverse(node->left,h+1);
            traverse(node->right,h+1);
        };
        traverse(root,1);
        return height;
    }
    //new
    int maxDepth(TreeNode* root) {    
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
    }
};