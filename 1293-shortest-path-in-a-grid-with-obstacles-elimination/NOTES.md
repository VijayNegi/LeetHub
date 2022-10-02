```
using pi = pair<int,int>;
class Solution {
public:
int shortestPath(vector<vector<int>>& grid, int k) {
int rows = grid.size();
int cols = grid[0].size();
auto cmp = [&](pi& left,pi& right) {
int r1 = left.first / cols;
int c1 = left.first % cols;
int r2 = right.first /cols;
int c2 = right.first % cols;
if(r1+c1 == r2+c1) return left.second < right.second;
return r1+c1 < r2+c2;
};
priority_queue<pi,vector<pi>,decltype(cmp)> pq(cmp);
pq.push({0,0});
int result=0;
while(pq.size()) {
auto p = pq.top();
}
return result;
}
};
```