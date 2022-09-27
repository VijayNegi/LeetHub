// Also impliment below solution
//https://leetcode.com/problems/push-dominoes/discuss/132482/Java-one-pass-in-place-13ms
class Solution {
public:
    // old solution
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
    // new 
    string pushDominoes1(string D) {
        int n = D.size();
        vector<int> forces(n,0);

        // Populate forces going from left to right
        int force = 0;
        for (int i = 0; i < n; ++i) {
            if (D[i] == 'R') force = n;
            else if (D[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Populate forces going from right to left
        force = 0;
        for (int i = n-1; i >= 0; --i) {
            if (D[i] == 'L') force = n;
            else if (D[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        string result;
        for (int f: forces)
            result.push_back(f > 0 ? 'R' : f < 0 ? 'L' : '.');
        return result;
    }
};