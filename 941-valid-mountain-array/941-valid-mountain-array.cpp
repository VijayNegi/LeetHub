class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        bool downhill = false;
        int count = 0;
        
        for(int i=1;i<n;++i)
        {
            if(!downhill && arr[i-1] < arr[i])
                count++;
            else if(!downhill && arr[i-1]> arr[i] && count)
            {
                ++count;
                downhill = true;
            }
            else if(downhill && arr[i-1] > arr[i])
                ++count;
            else
                break;
        }
        return downhill && (count +1 == n);
        
    }
};