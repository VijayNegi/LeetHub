typedef long long ll;
const int mod = 1e9+7;
class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        
        int g = gcd(a,b);
        //cout<<"g="<<g<<"\n";
        int lower = min(a,b);
        if(g==lower)
            return ((ll)lower*n)%mod;
        int lcm = (a*b)/g;
        //cout<<"lcm="<<lcm<<"\n";
        int period = (lcm/a) + (lcm/b) - 1;
        //cout<<"period="<<period<<"\n";
        int m = n/period;
        int r = (n%period);
        //cout<<"m="<<m<<"\n";
        //cout<<"r="<<r<<"\n";
        vector<int> first{0};//(period+1,0);
        
        for(int i = 1; i<=lcm/a;i++)
        {
            first.push_back(a*i);
        }
        for(int i = 1; i<=lcm/b;i++)
        {
            first.push_back(b*i);
        }
        sort(begin(first),end(first));
        
        return ((ll)m*lcm + first[r])%mod;
        
            
    }
};