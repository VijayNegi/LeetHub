class Solution {
public:
    
    int gcd(int a,int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int mirrorReflection(int p, int q) {
        int g = gcd(p,q);
        int lcm = (p*q)/g;
        int count = lcm/q;
        if(count%2==0) {
            return 2;
        }
       
        int count1 = lcm/p;
        if(count1%2)
            return 1;
        return 0;
        
    }
};