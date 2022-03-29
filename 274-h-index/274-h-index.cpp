class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations),end(citations));
        int result=0;
        for(int i=0;i<n;++i)
        {
            if(citations[i] >= n-i)
                result = max(result,n-i);
        }
        return result;
    }
};