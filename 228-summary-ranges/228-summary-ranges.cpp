class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0)
            return result;
        int start=nums[0],end=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i] == end+1)
                ++end;
            else
            {
                string t;
                if(start==end)
                    t = to_string(start);
                else
                    t = to_string(start) + "->"+to_string(end);
                result.push_back(t);
                start=end= nums[i];
            }
        }
        string t;
        if(start==end)
            t = to_string(start);
        else
            t = to_string(start) + "->"+to_string(end);
        result.push_back(t);
        return result;
    }
};