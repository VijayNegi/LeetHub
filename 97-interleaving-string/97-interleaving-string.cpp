class Solution {
public:
    // 55 ms
    bool isInterleave1(string s1, string s2, string s3) {
        int n1 = s1.size(),n2=s2.size(),n3= s3.size();
        if(n3 != n1+n2)
            return false;
        vector<vector<vector<int>>> mem(n1+1,vector(n2+1,vector(n3+1,-1)));
        function<bool(int,int,int)> dfs = 
            [&](int id1,int id2,int id3) -> bool {
                if(id1==n1 && id2==n2 && id3==n3)
                    return true;
                if(mem[id1][id2][id3]>=0)
                    return mem[id1][id2][id3];
                if(id1!=n1 && id2!=n2 && s1[id1] == s3[id3] && s2[id2]== s3[id3])
                    return mem[id1][id2][id3] = dfs(id1+1,id2,id3+1) || dfs(id1,id2+1,id3+1);
                if(id1!=n1 && s1[id1] == s3[id3])
                    return mem[id1][id2][id3] = dfs(id1+1,id2,id3+1);
                else if(id2!=n2 && s2[id2]== s3[id3])
                    return mem[id1][id2][id3] = dfs(id1,id2+1,id3+1);
                else 
                    return mem[id1][id2][id3] = false;
        };
        return dfs(0,0,0);
    }
    // 55 ms
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(),n2=s2.size(),n3= s3.size();
        if(n3 != n1+n2)
            return false;
        vector<vector<int>> mem(n1+1,vector(n2+1,-1));
        function<bool(int,int,int)> dfs = 
            [&](int id1,int id2,int id3) -> bool {
                if(id1==n1 && id2==n2 && id3==n3)
                    return true;
                if(mem[id1][id2]>=0)
                    return mem[id1][id2];
                if(id1!=n1 && id2!=n2 && s1[id1] == s3[id3] && s2[id2]== s3[id3])
                    return mem[id1][id2] = dfs(id1+1,id2,id3+1) || dfs(id1,id2+1,id3+1);
                if(id1!=n1 && s1[id1] == s3[id3])
                    return mem[id1][id2] = dfs(id1+1,id2,id3+1);
                else if(id2!=n2 && s2[id2]== s3[id3])
                    return mem[id1][id2] = dfs(id1,id2+1,id3+1);
                else 
                    return mem[id1][id2] = false;
        };
        return dfs(0,0,0);
    }
};