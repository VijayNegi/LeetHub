class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int n = height.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int h = min(height[l],height[r]);
            result = max(result,h*(r-l));
            if(height[l]<height[r])
            {
                int l1=l;
                while(l<r && height[l]<=height[l1])
                    ++l; 
            }
            else
            {
                 int r1=r;
                 while(l<r && height[r]<=height[r1])
                    --r; 
            }
        }
        return result;
        
    }
};