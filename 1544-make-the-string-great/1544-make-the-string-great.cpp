class Solution {
public:
    string makeGood(string s) {
        int l=0,r=1;
        while(r<s.size()) {
            if(l<0)
                s[++l] = s[r++];
            else {
                if((isupper(s[l]) && islower(s[r])) || (islower(s[l]) && isupper(s[r])))
                   {
                        int d1,d2;
                       if(isupper(s[l]))   d1 = s[l]-'A';
                       else                d1 = s[l]-'a';
                       if(isupper(s[r]))   d2 = s[r]-'A';
                       else                d2 = s[r]-'a';
                       if(d1==d2)
                       {
                           --l,++r;
                           continue;
                       }
                   }
                   s[++l] = s[r++];
            }    
        }
        s.resize(l+1);
        return s;
    }
};