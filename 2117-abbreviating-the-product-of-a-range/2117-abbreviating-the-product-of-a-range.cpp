class Solution {
public:
    // https://leetcode.com/problems/abbreviating-the-product-of-a-range/discuss/1647115/Modulo-and-Double
    // 20 ms
    string abbreviateProduct(int left, int right) {
        long long suff = 1, c = 0, total = 0, max_suff = 100000000000;
        double pref = 1.0;
        for (int i = left; i <= right; ++i) {
            pref *= i;
            suff *= i;
            while (pref >= 100000) {
                pref /= 10;
                total = total == 0 ? 6 : total + 1; 
            }
            while (suff % 10 == 0) {
                suff /= 10;
                ++c;
            }
            suff %= max_suff;
        }
        string s = to_string(suff);
        return to_string((int)pref) + (total - c <= 10 ? "" : "...") 
                + (total - c < 5 ? "" : s.substr(s.size() - min(5LL, total - c - 5))) + "e" + to_string(c);
    }
    // https://leetcode.com/problems/abbreviating-the-product-of-a-range/discuss/3512713/Basic-Maths-Shortest-C%2B%2B-Cleanest-Solution-or-Easy-to-Understand-or
    // some math: 350 ms
    string abbreviateProduct2(int left, int right) {
    
        string Ans = "1",Prefix ="1";
        int count = 0;
        for(int i=left;i<=right;i++)
        {
            Ans = to_string(i*stol(Ans));
            while(Ans.back()=='0') Ans.pop_back() , count++;
            if(Ans.size()>12)
            Ans =Ans.substr(Ans.size()-12); 
        }
        
        long double SumLog= 0;
        for(int i=left;i<=right;i++)
        SumLog += log10(i);
        string P =to_string(floor(pow(10,4.0+(SumLog-long(SumLog)))));
        
        if(Ans.size()>10)
        Ans = (P.size()>5?P.substr(0,5):P) +"..." + Ans.substr(Ans.size()-5);
        
        return Ans+"e"+to_string(count);
    }
};