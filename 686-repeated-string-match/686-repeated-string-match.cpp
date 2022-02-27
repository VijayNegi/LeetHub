class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string temp;
        int bn = b.size();
        int count=0;
        while(temp.size() < bn)
        {
            temp+=a;
            ++count;
        }
        
        if(temp.find(b) != string::npos)
            return count;
        
        temp += a;
        ++count;
        if(temp.find(b) != string::npos)
            return count;
        return -1;
    }
};