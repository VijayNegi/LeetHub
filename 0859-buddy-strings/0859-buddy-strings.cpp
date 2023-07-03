class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        if(s == goal){
            sort(begin(s),end(s));
            for(int i=1;i<s.size();++i)
                if(s[i] == s[i-1])
                    return true;
            return false;
        }
        int difference=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!= goal[i])
                ++difference;
        }
        if(difference!=2)
            return false;
        int l1=-1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!= goal[i] && l1 ==-1)
                l1=i;
            else if(s[i]!= goal[i])
            {
                if(s[i] == goal[l1] && s[l1] == goal[i])
                    return true;
                else 
                    return false;
            }
        }
        
        return false;
    }
};