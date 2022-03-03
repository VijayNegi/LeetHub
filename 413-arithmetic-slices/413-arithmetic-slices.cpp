class Solution {
public:
    int numberOfArithmeticSlices1(vector<int>& nums) {
        vector<int> map(2001,0);
        int n = nums.size();
        for(int i=0;i<n;++i)
            map[nums[i]+1000]++;
        int result=0;
        for(int i=0;i<2001;++i)
        {
            if(map[i]>2)
                result += map[i]-2;
            int j=i+1;
            
            while(j<n && map[j]==0)
                ++j;
            if(j >n)
                continue;
            int diff=j-i;
            while(j<n && map[j]>0)
                j+=diff;
            int count = (j-i)/diff;
            --count;
            if(count>2)
                result +=count-2;
        }
        return result;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int n = nums.size();
        int result=0;
        for(int i=0;i<n-1;++i)
        {
            int j=i+1;
            int diff = nums[i+1]-nums[i];
            while(j<n && nums[j]-nums[j-1] == diff)
                ++j;
            int count = j-i;
            if(count>2)
                result += count -2;
        }
        return result;
    }
};