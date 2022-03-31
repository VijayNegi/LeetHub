class Solution {
public:
int splitArray(vector<int>& nums, int m) {
int sum = accumulate(begin(nums),end(nums),0);
int n = nums.size();
int target = sum/m;
//cout<<"t="<<target<<endl;
int result = INT_MAX;
int seg = 1;
function<void(int,int,int)> dfs = [&](int idx,int rsum,int res)
{
if(seg==m)
{
//cout<<endl;
result = min(result,max(res,rsum));
return;
}
++seg;
int tsum = nums[idx];
for(int i=idx+1;i<n-(m-seg);++i)
{
if(tsum >=target)
{
//cout<<i<<" ";
dfs(i,rsum-tsum,max(res,tsum));
break;
}
else if((tsum+nums[i])>=target)
{
//cout<<i<<" ";
dfs(i,rsum-tsum,max(res,tsum));
}
tsum += nums[i];
}
--seg;
return;
};
dfs(0,sum,0);
return result;
}
};