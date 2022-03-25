class Solution {
public:
int twoCitySchedCost(vector<vector<int>>& costs) {
int n = costs.size();
sort(begin(costs),end(costs));
int result=0;
for(int i=0;i<n;++i)
{
if(i<n/2)
result += costs[i][0];
else
result += costs[i][1];
}
auto cmp = [](vector<int>& left,vector<int>& right){ return left[1]<right[1];};
sort(begin(costs),end(costs),cmp);
int result1=0;
for(int i=0;i<n;++i)
{
if(i<n/2)
result1 += costs[i][0];
else
result1 += costs[i][1];
}
return min(result,result1);
}
};