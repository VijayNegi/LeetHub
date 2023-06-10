class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum-=n;
        int i=0;
        while(true){
            
            int l = max(index - i,0);
            int r = min(index + i,n-1);
            int s = r-l+1;
            //cout<<i<<" "<<s<<" "<<maxSum<<endl;
            if(maxSum<s )
                break;
            if(s==n){
                i += maxSum/s;
                maxSum %=s;
            }
            else{
                ++i;
                maxSum-=s;
            }
        }
        return i+1;
    }
};
