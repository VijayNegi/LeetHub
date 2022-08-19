class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> freq(2002,0);
        for(auto& n:nums)
            freq[n+1000]++;
        //priority_queue<int> pq;
        //cout<<"test";
        vector<int> seq;
        for(auto& k: freq) {
            // if(k>0)
            //     cout<<k<<" ";
            if( k > seq.size()) {
                seq.insert(seq.end(),k-seq.size(),0);
                for(auto& s: seq)
                    ++s;
            }
            else if(k == seq.size()) {
                for(auto& s: seq)
                    ++s;
            }
            else {
                for(int i=0;i<(seq.size()-k);++i)
                    if(seq[i]<3)
                        return false;
                int s = (seq.size()-k);
                for(int i=0; s<seq.size();++i,++s)
                    seq[i] = seq[s];
                seq.resize(k);
                for(auto& s: seq)
                    ++s;
            }
        }
        for(auto& s: seq)
                if(s<3)
                    return false;
        return true;
    }
};
 
    
    
    