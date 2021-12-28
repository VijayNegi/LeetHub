#define TRIE_LEN 26
struct trie
{
    bool end;
    vector<trie*> next;
    trie()
    {
        next = vector<trie*>(TRIE_LEN,nullptr);
        end = false;
    }
    void insert(string s, int idx)
    {
        if(s.size() == idx)
            return;
        // int c = s[idx];
        // c-=a;
        // if(next[c] == nullptr)
        //     next[c] = new trie;
        // next[c].insert(s,idx+1);
        
        int n = s.size();
        trie* node = this;
        while(node!=nullptr)
        {
            if(idx==n)
            {
                node->end = true;
                return;
            }
            int c = s[idx];
            c-='a';
            if(!node->next[c])
                node->next[c] = new trie();
            node = node->next[c];
            ++idx;
        }
    }
    
    list<int> search(string s, int idx)
    {
        list<int> res;
        int n = s.size();
        trie* node = this;
        while(node!=nullptr)
        {
            if(node->end)
                res.push_front(idx);
            if(idx==n)
                break;
            int c = s[idx];
            c-='a';
            if(!node->next[c])
                break;
            node = node->next[c];
            ++idx;
        }
        return res;
    }
};
class Solution {
public:
    // TLE
    bool wordBreak1(string s, vector<string>& wordDict) {
        vector<vector<string>> wmap(26);
        for(auto& w:wordDict)
        {
            wmap[w[0]-'a'].push_back(w);
        }
        
        function<bool(string,int)> recurse =  [&](string s,int idx)
        {
            if(s.size() == idx)
                return true;
            for(auto& w:wmap[s[idx]-'a'])
            {
                int t=0;
                int i=idx;
                while(t<w.size() && i<s.size())
                {
                    if(w[t] != s[i])
                        break;
                    ++t;
                    ++i;
                }
                if(t==w.size())
                    if(recurse(s,idx+t))
                        return true;
            }
            return false;
        };
        return recurse(s,0);
    }
    // TRIE based solution
    bool wordBreak(string s, vector<string>& wordDict) {
        trie dict;
        for(auto& w:wordDict)
            dict.insert(w,0);
        int n = s.size();
        list<int> q{0};
        vector<bool> check(n,false);
        while(!q.empty())
        {
            int i = q.front();
            q.pop_front();
            if(check[i])
                continue;
            check[i] = true;
            auto l = dict.search(s,i);
            if(l.front() == n)
                return true;
            q.insert(q.begin(),l.begin(),l.end());
        }
        
        return false;
    }
    
};