class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int dots=0, n = s.size();
        vector<string> result;
        function<void(string,int )> dfs = [&](string c,int p){
            if(p==n && dots==4){
                c.pop_back();
                result.push_back(c);
                return;
            }
            if(p==n || dots==4) return;
            
            //if(s[p]=='0') return;
            int i=0,num=0;
            while(i<3 && (i+p)<n){
                if(i>0 && num==0) break;
                num = num*10 + s[i+p]-'0';
                if(num>255 ) break;
                c+= s[i+p];
                ++dots;
                dfs(c+".",i+p+1);
                --dots;
                ++i;
            }
        };
        dfs("",0);
        return result;
    }
};