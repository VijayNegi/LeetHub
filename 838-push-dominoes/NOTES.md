class Solution {
public:
string pushDominoes(string dominoes) {
int n = dominoes.size();
vector<int> l2r(n,INT_MAX);
int dis=0;
for(int i=n-1;i>=0;--i) {
if(dominoes[i]=='R')
dis=0;
else if(dominoes[i]=='L' || dis<0) {
if(dominoes[i]=='L')
dis=0;
l2r[i] = --dis;
}
}
for(auto& k:l2r)
cout<<k<<" ";
cout<<endl;
dis=0;
for(int i=0;i<n;++i) {
if(dominoes[i]=='L')
dis=0;
else if(dominoes[i]=='R' || dis>0) {
if(dominoes[i]=='R')
dis=1;
if(abs(l2r[i]) == dis)
l2r[i]=0;
else if(abs(l2r[i])> dis)
l2r[i] = dis++;
}
}
for(auto& k:l2r)
cout<<k<<" ";
cout<<endl;
string result;
for(auto& k:l2r) {
if(k==INT_MAX) result.push_back('.');
else if(k<0) result.push_back('L');
else if(k>0) result.push_back('R');
}
return result;
}
};