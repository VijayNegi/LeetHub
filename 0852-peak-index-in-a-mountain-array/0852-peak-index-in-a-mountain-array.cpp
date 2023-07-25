class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;
        for(int i=1;i<n;++i){
            if(arr[i]>arr[i-1])
                idx = i;
        }
        return idx;
    }
};