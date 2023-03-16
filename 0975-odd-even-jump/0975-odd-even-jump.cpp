class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        set<int> s;
        map<int,int> val2idx;
        int n = arr.size(),result=0;
        vector<vector<int>> reach(n,vector<int>(2,0));
        reach[n-1][0] = reach[n-1][1] = 1;
        ++result;
        s.insert(arr[n-1]);
        val2idx[arr[n-1]] = n-1;
        for(int i=n-2;i>=0;--i){
            auto it = s.lower_bound(arr[i]);
            if(it != s.end()){
                reach[i][1] = reach[val2idx[*it]][0];
                if(*it == arr[i])
                    reach[i][0] = reach[val2idx[*it]][1];
                else if(it != s.begin()){
                    auto p = prev(it);
                    reach[i][0] = reach[val2idx[*p]][1];
                } 
            }
            else {
                 auto p = prev(it);
                reach[i][0] = reach[val2idx[*p]][1];
            }
            if( reach[i][1] ) //reach[i][0] ||
                ++result;
            val2idx[arr[i]] = i;
            s.insert(arr[i]);
        }
        return result;
    }
};