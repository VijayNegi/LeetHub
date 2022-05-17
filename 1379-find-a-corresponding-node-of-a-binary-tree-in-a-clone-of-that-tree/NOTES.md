class Solution {
public:
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
vector<TreeNode*> inCloned;
vector<TreeNode*> inTarget;
function<void(TreeNode*,vector<TreeNode*>&)> inorder = [&](TreeNode* node,vector<TreeNode*>& vec){
if(!node)
return;
inorder(node->left, vec);
vec.push_back(node);
inorder(node->right,vec);
};
inorder(cloned,inCloned);
inorder(target,inTarget);
int ntree = inCloned.size();
int nsubtree = inTarget.size();
for(int i=0;i<=ntree-nsubtree;++i) {
int k=0;
for(;k<nsubtree;++k)
if(inCloned[i+k]->val != inTarget[k]->val )
break;
if(k==nsubtree)
return inCloned[i];
}
return nullptr;
}
};