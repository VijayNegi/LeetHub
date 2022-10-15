```
class Solution {
public:
int getLengthOfOptimalCompression(string s, int k) {
int rlen=0;
char pre = ' ';
vector<int> len;
//int currlen = 0;
for(auto c:s) {
if(c!= pre) {
if(rlen)
len.push_back(rlen);
rlen=0;
pre = c;
}
++rlen;
}
len.push_back(rlen);
sort(begin(len),end(len));
int tlen=0;
for(auto& l:len) {
cout<<l<<" ";
if(k<=0){
++tlen; // char
if(l!=1)
tlen+=to_string(l).size();
}
else {
if(k>=l){
k-=l;
}
else {
l-=k;
k=0;
++tlen;
if(l!=1)
tlen+=to_string(l).size();
}
}
}
return tlen;
}
};
```