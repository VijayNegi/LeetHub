class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        
        int l=0,r=people.size()-1;
        int ans = 0;
        while(l<=r)
        {
            if(l==r)
                return ans+1;
            else
            {
                if(people[l]+people[r]<= limit)
                    ++l,--r,++ans;
                else
                    --r,++ans;
            }
        }
        return ans;
    }
};