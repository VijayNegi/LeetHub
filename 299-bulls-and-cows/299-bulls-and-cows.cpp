class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        for(int i=0;i<n;++i)
        {
            if(secret[i] == guess[i])
                ++bulls;
            else
            {
                mp[guess[i]]++;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(secret[i] != guess[i])
            {
                //auto it = mp.find(secret[i]);
                if(mp[secret[i]])
                {
                    ++cows;
                    mp[secret[i]]--;
                }
            }
        }
        
        string res;
        res = to_string(bulls) + "A" + to_string(cows) + "B"; 
        return res;
    }
};