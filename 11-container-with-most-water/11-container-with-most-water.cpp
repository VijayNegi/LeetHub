class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        
        while(l<r)
        {
            int h = min(height[l],height[r]);
            int water = h*(r-l);
            maxWater = max(maxWater,water);
            if(height[l]<height[r])
                ++l;
            else
                --r;
        }
        
        return maxWater;
    }
};