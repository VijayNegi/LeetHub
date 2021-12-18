class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        int p = 0;
        int t = n;
        vector<int> num;
        while(t>0)
        {
            ++p;
            num.push_back(t%10);
            //cout<<t%10<<",";
            t/=10;
        }
        //cout<<endl;
        
        int d = digits.size();
        vector<int> di(d,0);
        for(int i=0;i<d;++i)
        {
            di[i] = digits[i][0] - '0';
            //cout<<di[i]<<"-";
        }
        //cout<<endl;
        
        function<int(int)> countless = [&](int k){
            auto it = upper_bound(di.begin(),di.end(),k);
            return distance(di.begin(),it);
        };
        
        int res = 0;
        
        int q = 1;
        int mul = d;
        while(q!= p)
        {
            res += mul;
            mul *= d;
            ++q;
        }
        //cout<<"res = "<<res<<endl;
        
        for(int i=p-1;i>=0;--i)
        {
            //cout<<"digit="<<num[i]<<endl;
            int k = countless(num[i]);
            //cout<<"less k="<<k<<endl;
            if(k==0)
                break;
            if(di[k-1] < num[i])
            {
                res += k * pow(d,i);
                break;
            }
            else
            {
                //cout<<"dalta = "<< (k-1)* pow(d,i)<<endl;
                res += (k-1) * pow(d,i);
                if(i==0)
                    ++res;
            }
               
            //cout<<"res ="<<res<<endl;
        }
        
        return res;
    }
};