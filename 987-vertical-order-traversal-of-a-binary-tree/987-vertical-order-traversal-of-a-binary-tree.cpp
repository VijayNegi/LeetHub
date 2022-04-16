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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        auto cmp =  [](pair<int,TreeNode*> &left,pair<int,TreeNode*> &right)
        {
            if(left.first == right.first)
                return left.second->val > right.second->val;
            return left.first > right.first;
        };

        priority_queue<pair<int, TreeNode*>,vector<pair<int, TreeNode*>> , decltype(cmp)> q(cmp);
        q.push({0,root});
        vector<pair<int, TreeNode*>> level;
        while(!q.empty())
        {
            auto pr = q.top();
            q.pop();
            int pos = pr.first;
            TreeNode* node = pr.second;
            mp[pos].push_back( node->val);
            if(node->left)
                level.push_back({pos-1,node->left});
            if(node->right)
                level.push_back({pos+1,node->right});
            if(q.empty())
            {
                for(auto p:level)
                    q.push(p);
                level.clear();
                //q.swap(qq);
                //swap(q, qq);
                //qq.clear();
            }
        }
        
        vector<vector<int>> res;
        for(auto vec:mp)
            res.push_back(vec.second);
        return res;
    }
};