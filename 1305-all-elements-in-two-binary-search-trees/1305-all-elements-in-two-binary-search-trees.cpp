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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res;
        
        function<void(TreeNode*,vector<int>&)> ascTrees = [&](TreeNode* node,vector<int>& asc)
        {
            if(!node)
                return;
            ascTrees(node->left,asc);
            asc.push_back(node->val);
            ascTrees(node->right,asc);
        };
        
        vector<int> t1,t2;
        ascTrees(root1,t1);
        ascTrees(root2,t2);
        
        int i1=0,i2=0;
        while(i1<t1.size() && i2<t2.size())
        {
            if(t1[i1]<=t2[i2])
                res.push_back(t1[i1++]);
            else 
                res.push_back(t2[i2++]);
        }
        
        if(i1<t1.size())
            res.insert(res.end(),t1.begin()+i1,t1.end());
        if(i2<t2.size())
            res.insert(res.end(),t2.begin()+i2,t2.end());
        return res;
    }
};