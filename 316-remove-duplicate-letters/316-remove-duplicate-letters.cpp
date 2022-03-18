class Solution {
public:
    string removeDuplicateLetters(string s) {
        string t = s;
        // sort followed by unique, to remove all duplicates
        //std::sort(t.begin(), t.end()); 
        //auto last = std::unique(t.begin(), t.end());
        //t.erase(last, t.end());
        //cout <<t<<endl;
        vector<int> map(26,0);
        vector<bool> seen(26,0);
        
        for(char c:s)
            map[c-'a']++;
        
        string result;
        int idx = 0;
        for(char c:s)
        {
        
            while(!seen[c-'a'] && !result.empty() && (result.back()>c) && (map[result.back() - 'a'] >= 1) )
            {
                //cout<<"pop"<<endl;
                seen[result.back() - 'a'] = false;
                result.pop_back();
                
            }
            if(!seen[c-'a'])
            {
                result.push_back(c);
                seen[c-'a'] = true;
            }
            //cout<<c<<" "<<result<<endl;
            --map[c-'a'];
        }
        return result;
    }
};