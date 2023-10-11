class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        vector<pair<int,int>> arrival;
        for(int i=0;i<n;++i){
            arrival.push_back({people[i],i});
        }
        sort(arrival.begin(),arrival.end());
        sort(flowers.begin(),flowers.end());
        priority_queue<int,vector<int>,greater<>> endQueue;
        int i=0;
        int f=0;
        int bloom=0;
        int fsize = flowers.size();
        vector<int> result(n,0);
        while(i<n){
            int k = arrival[i].first;
            int pos = arrival[i].second;
            // add all the flowers that had bloomed
            while(f<fsize && flowers[f][0]<=k){
                if(flowers[f][1]>=k){
                   endQueue.push(flowers[f][1]);
                    ++bloom;
                }
                ++f;
            }
           // remvoe all the flowers whos time has passed
            while(endQueue.size() &&  endQueue.top()<k ){
                endQueue.pop();
                --bloom;
            }
            result[pos] = bloom;
            ++i;
        }
        return result;
    }
};