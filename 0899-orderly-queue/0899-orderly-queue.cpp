class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        string res = s;
        if(k==1){
            string temp = s +s;
            for(int i=0;i<n;++i){
                int flag = false;
                for(int j=i;j<i+n;++j){
                    if(res[j-i] < temp[j])
                        break;
                    else if(res[j-i] > temp[j]){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    res = temp.substr(i,n);
                }
            }
        }
        else{
            sort(res.begin(),res.end());
        }
        return res;
    }
};