class Solution {
public:
    int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n= nums1.size();
        //sort(nums4.begin(),nums4.end());
        int res(0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    long sum = (long)nums1[i]+nums2[j]+nums3[k];
                    sum = -sum;
                    auto it = lower_bound(nums4.begin(),nums4.end(),sum);
                    while(it != nums4.end() && *it == sum )
                    {
                        ++res;
                        ++it;
                    }
                        
                }
            }
        }
        return res;
    }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)    {
        int n= nums1.size();
        //sort(nums4.begin(),nums4.end());
        unordered_map<long,int> sumMap;
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                long sum = (long)nums3[i] + nums4[j];
                sumMap[sum]++;
            }
        }
        int res(0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                long sum = (long)nums1[i] + nums2[j];
                if(sumMap[-sum])
                    res += sumMap[-sum];
            }
        }
        return res;
    }
};