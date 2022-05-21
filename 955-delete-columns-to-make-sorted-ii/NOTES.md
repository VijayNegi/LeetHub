// does not work
class Solution {
public:
int minDeletionSize(vector<string>& strs) {
int n = strs[0].size();
int result=0;
for(int i=0;i<n;++i) {
int j;
bool next = false;
for(j=1;j<strs.size();++j)
if( strs[j][i] <= strs[j-1][i]) {
next = true;
if( strs[j][i] < strs[j-1][i]) {
++result;
break;
}
}
if(!next)
break;
}
return result;
}
};