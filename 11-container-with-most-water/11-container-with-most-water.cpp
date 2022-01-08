class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxH = 0;
        while(l<r)
        {
            int h = min(height[l],height[r]);
            int water = h*(r-l);
            maxWater = max(maxWater,water);
            maxH = max(h,maxH);
            if(height[l]<height[r])
                while(l<r && height[l]<=maxH) ++l;
            else
                while(r>l && height[r]<=maxH) --r;
        }
        
        return maxWater;
    }
};