const int mod = 1e9+7;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int,int> freq;
        for(auto& a:arr)
            freq[a]++;
        long result=0;
        for(auto it= begin(freq);it!= end(freq);++it)
        {
            int num = it->first;
            long count = it->second;
            //cout<<num<<" "<<count<<" "<<result<<endl;
            if(num*3 == target && count>=3)
            {
                result += count*(count-1)*(count-2)/6;
                result = result % mod;
                //cout<<"1 "<<result<<endl;
            }
            if(target - num*2 > num && count>=2)
            {
                
                result += count*(count-1)*freq[target-2*num] /2;
                result = result % mod;
                //cout<<"12 "<<result<<endl;
            }
                
            auto it1 = it;
            ++it1;
            for(;it1!=end(freq);++it1)
            {
                int num1 = it1->first;
                int count1 = it1->second;
                int sum = target - num - num1;
                if(sum<num1)
                    continue;
                if(num1 == sum)
                {
                    // int res=0;
                    // for(int i=1;i<=count1-1;++i)
                    //         res+=i;
                    result += count*count1*(count1-1)/2;
                    result = result % mod;
                    //cout<<"2 "<<result<<endl;
                }
                else
                {
                    int count2 = freq[sum];
                    result += count*count1*(count2);
                    result = result % mod;
                    //cout<<"3 "<<result<<endl;
                }
            }
        }
        return result;
    }
    // TLE
    int threeSumMulti1(vector<int>& arr, int target) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        int result = 0;
        
        for(int i=0;i< n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                int s = target - arr[i] - arr[j];
                auto it = lower_bound(begin(arr)+j+1,end(arr),s);
                while(it!= arr.end() && *it==s)
                {
                    ++it,++result;
                }
                if(result>=mod)
                    result-=mod;
            }
        }
        return result;
    }
};