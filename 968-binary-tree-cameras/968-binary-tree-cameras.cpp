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
    int minCameraCover(TreeNode* root) {
        int result=0;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node)
                return 0;
            // if(!node->left && !node->right)
            //     return 1;
            int left = dfs(node->left);
            int right = dfs(node->right);
            if(left==1 || right==1) {
                ++result;
                return 2;
            }
            if(left==2 || right==2)
                return 0;
            return 1;
        };
        if(dfs(root)==1)
            ++result;
        return result;
    }
};