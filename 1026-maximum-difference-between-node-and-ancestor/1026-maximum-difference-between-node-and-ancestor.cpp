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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
    int dfs(TreeNode* node,int minAns,int maxAns){
        if(!node) return 0;
        int ans = abs(minAns-node->val);
        ans = max(ans,abs(maxAns - node->val));
        ans = max(ans,dfs(node->left, min(minAns,node->val),max(maxAns,node->val)));
        ans = max(ans,dfs(node->right, min(minAns,node->val),max(maxAns,node->val)));
        return ans;
    }
};