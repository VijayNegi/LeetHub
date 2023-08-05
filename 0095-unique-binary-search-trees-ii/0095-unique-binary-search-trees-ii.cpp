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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> result(n+1);
        result[0].push_back(nullptr);
        result[1].push_back(new TreeNode(1));
        for(int i=2;i<=n;++i){
            for(int j=0;j<i;++j){
                for(auto& l:result[i-1-j]){
                    for(auto& r:result[j]){
                        TreeNode* root = new TreeNode(i,l,clone(r));
                        result[i].push_back(root);
                    }
                }
            }
        }
        int val = 0;
        function<void(TreeNode*)> count = [&](TreeNode* node){
            if(!node) return;
            count(node->left);
            node->val = val++;
            count(node->right);
        };
        for(auto& root: result[n]){
            val = 1;
            count(root);
        }
        return result[n];
    }
private:
    TreeNode* clone(TreeNode* node) {
        if (node == NULL) {
            return NULL;
        }
        TreeNode* clonedNode = new TreeNode();
        clonedNode->left = clone(node->left);
        clonedNode->right = clone(node->right);
        return clonedNode;
    }
};