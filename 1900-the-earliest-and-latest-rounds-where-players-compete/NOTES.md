// initial code propabely incorrect
​
```
class Solution {
public:
vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
vector<int> result{1,1};
if(firstPlayer == n+1-secondPlayer)
return result;
int out = firstPlayer - 1 + n - secondPlayer;
int n1=n;
int r =1;
while(out>0)
{
out -= n1/2; // 9-
n1 = n1 - n1/2;
++r;
}
result[0]= r;
out = n-2;
r=1;
n1=n;
while(out>0)
{
out -= n1/2; //9-5, 4-3, 1-1 ,
n1 = n1 - n1/2;
++r;
}
result[1]= r;
return result;
}
};
```