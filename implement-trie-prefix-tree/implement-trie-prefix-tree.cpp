#define TRIE_LEN 26
class Trie {
    bool end;
    vector<Trie*> child;
public:
    Trie() {
        end= false;
        child = vector<Trie*>(TRIE_LEN,nullptr);
    }
    
    void insert(string word) {
        if(child[word[0]-'a']==nullptr)
        {
            child[word[0]-'a'] = new Trie();
        }
        child[word[0]-'a']->insert(word,1);
    }
    
    bool search(string word) {
        if(child[word[0]-'a']==nullptr)
            return false;
        return child[word[0]-'a']->search(word,1);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,0);
        
    }
private:
    void insert(string s,int idx)
    {
        if(idx>= s.size())
        {
            end = true;
            return;
        }
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            child[i] = new Trie();
        child[i]->insert(s,idx+1);
    }
    bool search(string s, int idx)
    {
        if(idx==s.size())
            return end;
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            return false;
        return child[i]->search(s,idx+1);
    }
    bool startsWith(string s,int idx)
    {
        if(s.size()== idx)
            return true;
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            return false;
        return child[i]->startsWith(s,idx+1);
    }
    
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */