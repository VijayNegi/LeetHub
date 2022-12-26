class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> smap;
        int n = words.size();
        for(int i=0;i<n;++i)
        {
            string s = words[i];
            reverse(begin(s),end(s));
            smap[s] = i;
        }
            
        vector<vector<int>> result;
        for(int i=0;i<n;++i)
        {
            string& s = words[i];
            int k = s.size();
            string pre = "";
            string suf = s;
            for(int j=0;j<=k;++j)
            {
                if(j>0 && isPalindrome(s,0,j-1) ) 
                {
                    //string str = s.substr(j); //suffix
                    if(smap.find(suf) != smap.end() && smap[suf] != i)
                        result.push_back({smap[suf],i});
                }
                if(isPalindrome(s,j,k-1))
                {
                    //string str = s.substr(0,j);
                    if(smap.find(pre) != smap.end() && smap[pre] != i)
                       result.push_back({i,smap[pre]});
                }
                if(j<k)
                {
                    pre += words[i][j];
                    suf.erase(0,1);
                }
            }
        }
        return result;
    }
    
    bool isPalindrome(string& s, int l,int r)
    {
        while(l<r)
            if(s[l++]!=s[r--])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs2(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();++i)
        {
            m[string(words[i].rbegin(),words[i].rend())] = i;
        }
        for(int i=0;i<words.size();++i)
        {
            string pre = "";
            string suf = words[i];
            for(int j=0;j<=words[i].size();++j)
            {
                
                if(j>0 && checkPalindrome1(pre) && m.find(suf)!=m.end() && m[suf]!=i)
                    result.push_back({m[suf],i});
                if(checkPalindrome1(suf) && m.find(pre)!=m.end() && m[pre]!=i)
                    result.push_back({i,m[pre]});
                if(j<words[i].size())
                {
                    pre += words[i][j];
                    suf.erase(0,1);
                }
            }
        }
        return result;
    }
    bool checkPalindrome1(const string& ss)
    {
        int s=-1,e=ss.size();
        while(++s<=--e)
            if(ss[s]!=ss[e])
                return false;
        return true;
    }
};