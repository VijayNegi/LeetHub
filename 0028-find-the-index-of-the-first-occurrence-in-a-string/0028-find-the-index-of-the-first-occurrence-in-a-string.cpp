class Solution {
public:
    //KMP
    int strStr(string haystack, string needle) {
        int h = haystack.size(),n = needle.size();
        if(n>h) return -1;
        if(n==0) return 0;
        auto pre = getPrefix(needle);
        int k=0;
        for(int i=0;i<h;++i){
            while(k>0 && needle[k] != haystack[i])
                k = pre[k-1];
            if(needle[k]==haystack[i])
                ++k;
            if(k==n) return i-n+1;
        }
        return -1;
    }
    vector<int> getPrefix(string str){
        int n = str.size();
        vector<int> pre(n,0);
        for(int i=1;i<n;++i){
            int j = pre[i-1];
            while(j>0 && str[i] != str[j])
                j = pre[j-1];
            if(str[i]==str[j])
                ++j;
            pre[i]=j;
        }
        return pre;
    }
};