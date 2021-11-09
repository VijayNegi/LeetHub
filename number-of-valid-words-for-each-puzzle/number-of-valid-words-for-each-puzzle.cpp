class Solution {
public:
    // optimized
        vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int sw = words.size();
        int sp = puzzles.size();
        vector<int> iw(sw,0);
        vector<int> ip(sp,0);
        vector<vector<int>> cbuckets(26);
        
        for(int i=0;i!=sw;++i)
        {
            for(const auto& c:words[i])
            {
                int pos = c -'a';
                iw[i] |= 1<<pos;
            }
        }
        
        for(int i=0;i!=sw;++i)
        {
            for(int j = 0; j!=26 ; ++j)
            {
                if(iw[i] & 1<<j)
                    cbuckets[j].push_back(iw[i]);
            }
            
        }
        
        for(int i=0;i!=sp;++i)
        {
            for(const auto& c:puzzles[i])
            {
                ip[i] |= 1<<(c-'a');
            }
        }
        vector<int> res(sp,0);
        // now search puzzles for every matching word
        for(int i=0;i!=sp;++i)
        {
            int count = 0;
            int firstChar = puzzles[i][0]-'a';
            //cout<< cbuckets[firstChar].size()<<" and First Char "<<firstChar<<endl;
            for(int w:cbuckets[firstChar])
            {
                // if(!(w & 1 << (puzzles[i][0]-'a')))
                //      continue;
                int x = w ^ ip[i];
                int y = x | ip[i];
                if(y != ip[i])
                   continue;
                   
                ++count;
            }
            
//             for(int j=0;j!=sw;++j)
//             {
//                 if(!(iw[j] & 1 << (puzzles[i][0]-'a')))
//                     continue;
               
//                 int x = iw[j] ^ ip[i];
//                 int y = x | ip[i];
//                 if(y != ip[i])
//                    continue;
                   
//                 ++count;
//             }
            res[i] = count;
        }
        
        
        return res;
        
    }
};