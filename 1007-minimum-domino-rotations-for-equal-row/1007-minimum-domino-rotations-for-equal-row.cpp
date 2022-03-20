class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> freqt(7,0),freqb(7,0);
        for(auto& n :  tops)
            ++freqt[n];
        for(auto& n : bottoms )
            ++freqb[n];
        int face= -1;
        int maxf = 0;
        for(int i=1;i<=6;++i)
            if(freqt[i]+freqb[i]>maxf)
            {
                maxf = freqt[i]+freqb[i];
                face = i;
            }
        
        if(maxf<n)
            return -1;
        int result=0;
        
        for(int i=0;i<n;++i)
        {
            if(tops[i]!=face && bottoms[i]!=face )
                return -1;
            if(freqt[face]>freqb[face])
            {
                if(tops[i]!=face)
                {
                    if(bottoms[i]==face)
                        ++result;
                }
            }
            else
            {
                if(bottoms[i]!=face)
                {
                    if(tops[i]==face)
                        ++result;
                }
            }
        }
        return result;
    }
};