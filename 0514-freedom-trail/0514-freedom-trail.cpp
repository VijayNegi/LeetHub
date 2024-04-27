class Solution {
public:
int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        int r = ring.size(), k = key.size();
        for(int i=0;i<r;i++) pos[ring[i]-'a'].push_back(i);
        vector<int> pre(r), cur(r,INT_MAX);
        for(int i=k-1;i>=0;i--) {
            for(int j=0;j<r;j++)
                for(int nxt:pos[key[i]-'a']) {
                    int dist = abs(j-nxt);
                    cur[j]=min(cur[j],min(dist,r-dist)+pre[nxt]);
                }
            swap(pre,cur);
            cur.assign(r,INT_MAX);
        }
        return pre[0]+k;
    }
};