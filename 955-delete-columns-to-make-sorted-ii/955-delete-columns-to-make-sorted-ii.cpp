// does not work
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int strn = strs.size();
        vector<int> skip(strn,false);
        int result=0;
        for(int i=0;i<n;++i) {
            int j;
            bool next = false;
            vector<int> temp(strn,false);
            for(j=1;j<strs.size();++j) {
                if(skip[j])
                    continue;
                if( strs[j][i] <= strs[j-1][i]) {
                    next = true;
                    if( strs[j][i] < strs[j-1][i]) {
                        ++result;
                        break;
                    }
                }
                else
                    temp[j] = true;
            }
            if(j==strn) {
                for(int t=1;t<strn;++t) {
                    skip[t] = skip[t] || temp[t]; 
                }     
            }  
            if(!next)
                break;
        }
        return result;
    }
};