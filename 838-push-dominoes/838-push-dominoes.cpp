// Also impliment below solution
//https://leetcode.com/problems/push-dominoes/discuss/132482/Java-one-pass-in-place-13ms
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int lastL = -1;
        int lastR = -1;
        
        for(int i=0;i<n;++i)
        {
            if(dominoes[i]=='L')
            {
                if(lastL>=lastR)
                {
                    int k=i;
                    while(k>lastL)
                        dominoes[k--] = 'L'; 
                }
                else
                {
                    int len = i - lastR;
                    int len2 = len/2;
                    if(len%2==0)
                        --len2;
                    while(len2>=0)
                    {
                        dominoes[lastR + len2] = 'R';
                        dominoes[i-len2] = 'L';
                        --len2;
                    }
                }
                lastL = i;
            }
            else if(dominoes[i]=='R')
            {
                if(lastR>lastL)
                {
                    int k=i;
                    while(k>lastR)
                        dominoes[k--] = 'R'; 
                }
                lastR = i;
            }
            
        }
        if(lastR>lastL)
        {
            int i=n-1;
            while(i>=lastR)
                dominoes[i--]='R';
        }
        return dominoes;
    }
};