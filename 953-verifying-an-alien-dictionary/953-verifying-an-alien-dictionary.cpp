class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       vector<int> idx(26,0);
        int i=0;
        for(char c:order)
        {
            idx[c-'a'] = i++;
        }
        
        for(int i=1;i<words.size();++i)
        {
            if(!compare(words[i-1],words[i], idx))
                return false;
        }
        return true;
    }
    
    bool compare(string w1,string w2,vector<int>& mapping)
    {
        int s1 = w1.size();
        int s2 = w2.size();
        int m = min(s1,s2);
        for(int i=0;i<m;++i)
        {
            if(mapping[w1[i]-'a'] == mapping[w2[i]-'a'])
                continue;
            else 
                return (mapping[w1[i]-'a'] <= mapping[w2[i]-'a']);
        }
        if(s1>s2)
            return false;
        return true;
    }
};