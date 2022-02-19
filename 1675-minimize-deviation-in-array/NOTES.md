using idVal = pair<int,int>;
class Solution {
public:
int minimumDeviation(vector<int>& nums) {
auto cmpmax = [&](idVal& left,idVal& right){ return left.second < right.second;};
auto cmpmin = [&](idVal& left,idVal& right){ return left.second > right.second;};
priority_queue<idVal,vector<idVal>,decltype(cmpmax)> maxq(cmpmax);
priority_queue<idVal,vector<idVal>,decltype(cmpmin)> minq(cmpmin);
int n = nums.size();
for(int i=0;i<n;++i)
{
minq.push({i,nums[i]});
maxq.push({i,nums[i]});
}
int mindev= INT_MAX;
while(true)
{
while(nums[maxq.top().first] != maxq.top().second)
maxq.pop();
while(nums[minq.top().first] != minq.top().second)
minq.pop();
int mintemp = maxq.top().second - minq.top().second;
if(maxq.top().second%2 ==0)