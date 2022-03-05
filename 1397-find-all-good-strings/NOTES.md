const int mod = 1e9 +7;
class Solution {
public:
bool between(string& s1,string& s2, string& t)
{
int n = s1.size();
for(int i=0;i<n;++i)
{
if(s1[i]> t[i] || s2[i]<t[i])
return false;
}
return true;
}
int findGoodStrings(int n, string s1, string s2, string evil) {
long evilCount = 0;
long goodCount = 0;
int e = evil.size();
///int n = s1.size();
for(int i=0;i<=(n-e);++i)
{
string temp = s1.substr(0,i) + evil + s1.substr(i+e);
cout<<temp<<endl;
int choice = abs(s1[i] - s2[i]) +1;
cout<<"good="<<choice<<endl;