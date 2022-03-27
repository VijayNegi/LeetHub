class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(begin(num1),end(num1));
        reverse(begin(num2),end(num2));
        string result;
        int i=0;
        int carry=0;
        while(i<num1.size() && i<num2.size())
        {
            int n = num1[i] + num2[i] - 2* '0' + carry;
            result += n%10 +'0';
            carry = n/10;
            ++i;
        }
        
        while(i<num1.size())
        {
            int n = num1[i] - '0' + carry;
            result += n%10 +'0';
            carry = n/10;
            ++i;
        }
        while(i<num2.size())
        {
            int n = num2[i] - '0' + carry;
            result += n%10+'0';
            carry = n/10;
            ++i;
        }
        if(carry)
            result += '0'+carry;
        reverse(begin(result),end(result));
        return result;
    }
};