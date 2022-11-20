class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        function<int(string&,int&)> dfs = [&](string& s, int& pos){
            int result=0;
            int curr=0;
            int sign = 1;
            while(pos<n){
                char c = s[pos];
                if(isdigit(c)){
                    curr *= 10 ;
                    curr +=  c-'0'; // why but need to break these two statement
                }
                else if(c=='-' || c=='+'){
                    result += curr*sign;
                    sign = (c=='-')? -1:1;
                    curr=0;
                }
                // else if(isspace(c)){
                //     result += curr*sign;
                //     curr=0;
                //     sign=1;
                // }
                else if(c=='(' || c==')'){
                    result += curr*sign;
                    if(c=='(' )
                        curr = dfs(s,++pos);
                    else{
                        return result;
                    }
                }
                ++pos;
            }
            result += curr*sign;
            return result;
        };
        int pos = 0;
        return dfs(s,pos);
    }
};