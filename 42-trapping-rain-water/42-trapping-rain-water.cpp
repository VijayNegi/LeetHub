class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> stk;
        int h=0;
        int result=0;
        for(int i=0;i<n;++i) {
            int h=0;
            //cout<<i<<"-"<<endl;
            while(stk.size() ) {
                int minh = min(height[stk.back()], height[i]);
                int height1 =  minh-h;
                int width = i- stk.back() -1;
                int area = width * (height1);
                result += area;
                //cout<<area<< " "<<width<<" "<<height1<<" -- "<<minh<<" "<<h<<endl;
                h = max(h, minh);
                if((height[stk.back()] <= height[i]))
                    stk.pop_back();
                else break;
            
            }
            // if(stk.empty())
            //     h=0;
            // else {
            //     int height1 =  height[i]-h;
            //     int width = i- stk.back() -1;
            //     int area = width * (height1);
            //     result += area;
            //     //cout<<area<< " "<<width<<" "<<height1<<" -- "<<height[i]<<" * "<<h<<endl;
            //     h = max(h, height[i]);
            // }
            
            if(height[i]>0)
                stk.push_back(i);
        }
        return result;
    }
};