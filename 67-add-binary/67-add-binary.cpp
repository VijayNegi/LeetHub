class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        
        int carry=0;
        int i=0;
        while(i<a.size() && i<b.size())
        {
            if(a[i]=='1' && b[i]=='1')
            {
                if(carry)
                    res.push_back('1');
                else
                {
                    res.push_back('0');
                    carry = 1;
                }
                    
            }
            else if(a[i]=='1' || b[i]=='1')
            {
                if(carry)
                    res.push_back('0');
                else
                    res.push_back('1');
            }
            else if(carry)
            {
                res.push_back('1');
                carry=0;
            }
            else
                res.push_back('0');
            ++i;
        }
        
        while(i<a.size())
        {
            if(a[i++]=='1')
            {
                if(carry)
                    res.push_back('0');
                 else
                    res.push_back('1');
            }
            else if(carry)
            {
                res.push_back('1');
                carry = 0;
            }
            else
                res.push_back('0');
                
        }
        
        while(i<b.size())
        {
            if(b[i++]=='1')
            {
                if(carry)
                    res.push_back('0');
                 else
                    res.push_back('1');
            }
            else if(carry)
            {
                res.push_back('1');
                carry = 0;
            }
            else
                res.push_back('0');
                
        }
        if(carry)
            res.push_back('1');
        
        reverse(begin(res),end(res));
        return res;
    }
};