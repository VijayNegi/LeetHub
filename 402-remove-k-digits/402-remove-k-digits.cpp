class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        if(num.size()<=k)
            return "0";
        
        for(auto c:num)
        {
            
            while(result.size() && result.back() > c && k )
            {
                result.pop_back();
                --k;
            }
            result.append(1,c);  
        }
        int s=0;
        // remove leading zeros
        while(s<result.size() && result[s++]=='0');
        result = result.substr(s-1);
        // remove remaining digits from back.
        while(result.size() && k--)
            result.pop_back();
       
        return (result.size()==0)?"0": result;
    }
};