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
    int result{INT_MAX};
public:
    int minDiffInBST(TreeNode* root) {
        minDiff(root);
        return result;
    }
    pair<int,int> minDiff(TreeNode* root){
        if(!root) return {1e6,-1};
        auto left = minDiff(root->left);
        auto right = minDiff(root->right);
        if(root->left)
            result = min(result,root->val - left.second);
        if(root->right)
            result = min(result,right.first - root->val);
        return {min(left.first,root->val), max(right.second,root->val)};
    }
};