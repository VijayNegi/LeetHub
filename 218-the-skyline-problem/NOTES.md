class Solution {
public:
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
vector<pair<int,int>> lines;
for(auto& b:buildings) {
lines.push_back({b[0],b[2]});
lines.push_back({b[1],-b[2]});
}
sort(begin(lines),end(lines));
int height = 0;
int previousX=-1;
vector<vector<int>> result;
for(auto& l:lines) {
int h = l.second, x = l.first;
cout<<x<<" "<<h<<" - "<<height<<endl;
if(h >= height) {
if(previousX>0) {
result.push_back({previousX,0});
}
result.push_back({x,h});
height = h;
previousX = -1;
}
else if(h<0) {
if(abs(h)>result.back()[1]) {
cout<<"abs(h)>height "<<endl;
result.back()[1] = abs(h);
cout<<"back- "<<result.back()[0]<<" "<<result.back()[1]<<endl;
previousX=x;
///result.push_back({x,0});
height =abs(h);
}
else if(abs(h)==height) {
cout<<"abs(h)==height "<<endl;
result.push_back({x,0});
cout<<"back- "<<result.back()[0]<<" "<<result.back()[1]<<endl;
previousX=-1;
height = 0;
}
}
}
return result;
}
};