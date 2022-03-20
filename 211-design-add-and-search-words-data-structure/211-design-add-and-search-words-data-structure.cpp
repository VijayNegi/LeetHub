#define LEN 26

struct Trie
{
    bool end{false};
    Trie* childs[LEN]; 
public:
    Trie()
    {
       fill(childs,childs+LEN,nullptr);
    }
    void add(string word)
    {
        Trie* curr = this;
        for(char& c:word)
        {
            if(!curr->childs[c-'a'])
                curr->childs[c-'a'] = new Trie();
            curr = curr->childs[c-'a'];
        }
        curr->end = true;
    }
    bool search(string& word)
    {
        return search(word,0);
    }
    bool search(string& word,int idx)
    {
        if(word.size() == idx)
            return end;
        char c = word[idx];
        if(c=='.')
        {
            for(int i=0;i<LEN;++i)
                if(childs[i] && childs[i]->search(word,idx+1))
                    return true;
        }
        else
        {
            if(childs[c-'a'] && childs[c-'a']->search(word,idx+1))
                return true;
            return false;
        }
        return false;
    }
};

class WordDictionary {
    Trie Dict;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Dict.add(word);
    }
    
    bool search(string word) {
        return Dict.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */