// Note - complexity is same for all solutions. Point is to optimize for sparse matrix
class Solution {
public:
    // self : TLE
    int largestOverlap1(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n1 = img1.size();
        int n2 = img2.size();
                int minX1,minX2,minY1,minY2,maxX1,maxX2,maxY1,maxY2;
        minX1=minX2=minY1=minY2=INT_MAX;
        maxX1=maxX2=maxY1=maxY2=0;
        
        for(int i=0;i<n1;++i){
            for(int j=0;j<n1;++j){
                if(img1[i][j]){
                    minX1 = min(minX1,i);
                    maxX1 = max(maxX1,i);
                    minY1 = min(minY1,j);
                    maxY1 = max(maxY1,j);
                }
            }
        }
        
        for(int i=0;i<n1;++i){
            for(int j=0;j<n1;++j){
                if(img2[i][j]){
                    minX2 = min(minX2,i);
                    maxX2 = max(maxX2,i);
                    minY2 = min(minY2,j);
                    maxY2 = max(maxY2,j);
                }
            }
        }
        
        function<int(int,int,int,int)> match = [&](int x1,int y1,int x2,int y2) {
            int count=0;
            int i1=x1,j1=y1,i2=x2,j2=y2;
            while(i1<=maxX1 && i2<=maxX2){
                if(img1[i1][j1]==1 && img2[i2][j2]==1)
                    ++count;
                ++j1,++j2;
                if(j1>maxY1 || j2 > maxY2){
                    ++i1,++i2;
                    j1=y1,j2=y2;
                }
            }
            return count;
        };
    
        
        int result=0;
        for(int x1=minX1;x1<=maxX1;++x1){
            for(int y1=minY1;y1<=maxY1;++y1){
                for(int x2=minX2;x2<=maxX2;++x2){
                    for(int y2=minY2;y2<=maxY2;++y2){
                        result = max(result,match(x1,y1,x2,y2));
                    }
                }
            }
        }
        return result;
    }
    // 114 ms
    // https://leetcode.com/problems/image-overlap/discuss/130623/C%2B%2BJavaPython-Straight-Forward
    int largestOverlap2(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i)
            if (A[i / N][i % N] == 1)
                LA.push_back(i / N * 100 + i % N);
        for (int i = 0; i < N * N; ++i)
            if (B[i / N][i % N] == 1)
                LB.push_back(i / N * 100 + i % N);
        for (int i : LA) for (int j : LB) count[i - j]++;
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res;
    }
    // 261 ms
    // https://leetcode.com/problems/image-overlap/discuss/1778665/C%2B%2B-Solution-using-Map
    int largestOverlap3(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>vec_a;
        vector<pair<int,int>>vec_b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vec_a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vec_b.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto [i1,j1]:vec_a){
            for(auto [i2,j2]:vec_b){
                mp[{i1-i2,j1-j2}]++;
                ans=max(ans,mp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
    }
    // only works in given constraints
    // https://leetcode.com/problems/image-overlap/discuss/2747543/10ms-C%2B%2B-convert-rows-to-integers-and-use-bit-manipulation-equivalent-to-O(n3)
    int largestOverlap(vector<vector<int>>& i1, vector<vector<int>>& i2) {
        int n=i1.size();
        vector<int> v1(n,0), v2(n,0); 
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i1[i][j]) v1[i]|=1<<j;
                if (i2[i][j]) v2[i]|=1<<j;
            }
        }
        int ans=0;
        for (int i=0; i<n; ++i) 
            for (int j=0; j<n; ++j) 
                ans=max(ans,overlap(v1,v2,i,j));        
        return ans;
    }
    int overlap(vector<int> &v1, vector<int> &v2, int x, int y) {
        array<int,4> ans={}; 
        int n=v1.size();
        for (int i=0; i<n-x; ++i) {
            ans[0]+=__builtin_popcount((v1[i]>>y)&v2[i+x]);
            ans[1]+=__builtin_popcount(v1[i]&(v2[i+x]>>y));
            ans[2]+=__builtin_popcount((v1[i+x]>>y)&v2[i]);
            ans[3]+=__builtin_popcount(v1[i+x]&(v2[i]>>y));
        }        
        return *max_element(ans.begin(), ans.end());    
    }
};