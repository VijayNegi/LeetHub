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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        int max_count=0;
        vector<int> result;
        function<void(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node) return;
            freq[node->val]++;
            if(freq[node->val]>max_count){
                max_count = freq[node->val];
                result.clear();
                result.push_back(node->val);
            }
            else if(freq[node->val] == max_count){
                result.push_back(node->val);
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return result;
    }
};