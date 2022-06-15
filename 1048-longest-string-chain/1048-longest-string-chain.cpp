class Solution {
public:
    int longestStrChain1(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()>r.size();});
        int result=1;
        unordered_map<string,int> s;
        for(auto& w:words)
            s[w]=1;
        for(auto& w:words) {
            int k = w.size();
            for(int i=0;i<w.size();++i) {
                string temp = w.substr(0,i) + w.substr(i+1, k-i-1);
                if(s[temp]) {
                    s[temp] = max(s[temp],s[w]+1);
                    result = max(result,s[temp]);
                }
            }
        }
        return result;
    }
    
    int longestStrChain(vector<string>& words) {
        int result=1;
        sort(words.begin(),words.end(),[](string &a, string &b){return a.size()<b.size();});
        int len = words.size();
        vector<int> dp(len,1);
        int currlen = -2;
        int preLen = -1;
        int preS=-2,preE=-2;
        for(int i=0;i<len;i++)
        {
            if(currlen != words[i].size())
            {
                
                preLen = currlen;
                preS = preE+1;
                preE = i-1;
                currlen = words[i].size();
                //cout<<"prelen="<<preLen<<" currlen="<<currlen<<" =["<<preS<<","<<preE<<"]"<<endl;
                // search current word in previous list
                if(preLen == currlen-1)
                {
                    string ss = words[i];
                    
                    for(int j=0;j<currlen;j++)
                    {
                        swap(ss[j],ss[0]);
                        
                        for(int k=preS;k<=preE;k++)
                        {
                            if(ss.substr(1,preLen)== words[k])
                            {
                                //cout<<"ss="<<ss.substr(1,preLen)<<" w="<<words[k]<<endl;
                                dp[i] = max(dp[i],dp[k]+1);
                                result = max(dp[i],result);
                            }
                        }
                    }
                }
            }
            else
            {
                if(preLen == currlen-1)
                {
                    string ss = words[i];
                    
                    for(int j=0;j<currlen;j++)
                    {
                        swap(ss[j],ss[0]);
                        
                        for(int k=preS;k<=preE;k++)
                        {
                            if(ss.substr(1,preLen)== words[k])
                            {
                                //cout<<"ss="<<ss.substr(1,preLen)<<" w="<<words[k]<<endl;
                                dp[i] = max(dp[i],dp[k]+1);
                                result = max(dp[i],result);
                            }
                        }
                    }
                }
            }
            
        }
        return result;
    }
};