class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        // assuming stations are sorted by distance
        int i=0;
        priority_queue<int> pq;
        
        int result=0;
        int pos=startFuel;
        while(pos<target){
            // get all stations we have passed
            for(;i<n;++i)
                if(stations[i][0]<=pos)
                    pq.push(stations[i][1]);
                else
                    break;
            if(pq.empty())
                return -1;
            pos += pq.top();
            pq.pop();
            ++result;
        }
        
        return result;
    }
};
