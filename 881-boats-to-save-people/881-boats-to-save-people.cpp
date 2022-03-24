class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        
        int l=0,r=people.size()-1;
        int ans = 0;
        while(l<=r)
        {
            ++ans;
            if(people[l]+people[r]<= limit) // if lightest person can be adjusted with heaivy person then do so.
                ++l;
            --r; // move haviest persion
        }
        return ans;
    }
};