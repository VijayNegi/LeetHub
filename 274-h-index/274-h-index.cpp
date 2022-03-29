class Solution {
public:
    // AC but it makes more sense to sort citations in reverse
    int hIndex2(vector<int>& citations) {
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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations),end(citations), greater<int>());
        int result=0;
        for(int i=0;i<n;++i)
        {
            if(citations[i] >= i+1)
                result = max(result,i+1);
        }
        return result;
    }
    int hIndex1(vector<int>& citations) {
        int n = citations.size(), h = 0;
        int* counts = new int[n + 1]();
        for (int c : citations)
            counts[min(c, n)]++;
        for (int i = n; i; i--) {
            h += counts[i];
            if (h >= i) return i;
        }  
        return h;
    }
};