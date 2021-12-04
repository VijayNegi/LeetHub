#define TRIE_LEN 26
struct Trie
{
    Trie* next[TRIE_LEN];
    bool leaf;
    Trie()
    {
        fill(next,next+TRIE_LEN,nullptr);
        leaf = false;
    }
    ~Trie()
    {
        for(int i=0;i<TRIE_LEN;++i)
        {
            if(next[i])
                delete next[i];
        }
    }
    void insert(string& str,int pos)
    {
        if(pos<str.size())
        {
            int ch = str[pos]-'a';
            if(!next[ch])
                next[ch] = new Trie();
            next[ch]->insert(str,pos+1);
        }
        else
            leaf = true;
    }
    void insertReverse(string& str,int pos)
    {
        if(pos>=0)
        {
            int ch = str[pos]-'a';
            if(!next[ch])
                next[ch] = new Trie();
            next[ch]->insertReverse(str,pos-1);
        }
        else
            leaf = true;
    }
    bool search(string& str, int pos)
    {
        if(leaf)
            return leaf;
        if(pos<str.size())
        {
            if(next[str[pos]-'a'])
                return next[str[pos]-'a']->search(str,pos+1);
        }
        return leaf;
    }
    bool searchDq(deque<int>::reverse_iterator it, deque<int>::reverse_iterator itend)
    {
        if(leaf)
            return leaf;
        if(it!=itend)
        {
            if(next[*it])
                return next[*it]->searchDq(it+1,itend);
        }
        return leaf;
    }
};
class StreamChecker {
    Trie T;
    deque<int> dq;
public:
    StreamChecker(vector<string>& words) {
        for(int i =0;i< words.size();++i)
        {
            T.insertReverse(words[i],words[i].size()-1);
        }
        
    }
    
    bool query(char letter) {
        dq.push_back(letter - 'a');
        return T.searchDq(dq.rbegin(),dq.rend());
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */