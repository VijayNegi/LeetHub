class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbed, int n) {
        int k = fbed.size();
        int result=0;
        for(int i=0;i<k;i++){
            if(!fbed[i]){
                if(i>0 && fbed[i-1]) continue;
                if(i<k-1 && fbed[i+1]) continue;
                fbed[i]++;
                ++result;
            }
        }
        return result>=n;
    }
};