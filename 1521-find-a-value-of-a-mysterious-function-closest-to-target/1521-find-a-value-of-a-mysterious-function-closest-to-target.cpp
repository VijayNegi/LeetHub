class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        set<int> s;
        int n = arr.size();
        int res=INT_MAX;
        for(int i=n-1;i>=0;--i){
            set<int> temp;
            temp.insert(arr[i]);
            res = min(res,abs(target-arr[i]));
            for(auto v: s) {
                int val = v & arr[i];
                res = min(res,abs(target-val));
                temp.insert(val);
            }
            s = temp;
        }
        return res;
    }
};