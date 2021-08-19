class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> comm0(n+1,0);
        vector<int> comm1(n+1,0);
        
        for(int i=0;i<n;++i)
        {
            if(i>0)
            {
                comm0[i] = comm0[i-1];
                comm1[i] = comm1[i-1];
            }
            if(s[i]=='0')
            {
                comm0[i]++;
            }
            else
                comm1[i]++;
        }
        int minF = n;
        for(int i=0 ; i<n; ++i)
        {
            //cout<<" i="<<i<<endl;
            if(i==0)
            {
                minF = min(minF, comm0[n-1]); // flip all zero after it;
            }
            else
            {
                minF = min(minF, comm1[i-1] + comm0[n-1]- comm0[i-1]);
            }
            //else if(i==n-1)
                minF = min(minF, comm1[n-1]); // flip all ones before it;
            //cout<<" i="<<i<<" min="<<minF<<endl;
        }
        return minF;
    }
};