class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int r=0;r<rows;++r)
            for(int c=1;c<cols;++c)
                matrix[r][c] += matrix[r][c-1];
        int result=0;
        for(int c1 =0;c1<cols;++c1)
            for(int c2=0;c2<=c1;++c2) {
                vector<int> rowsum(rows,0);
                long sum=0;
                multiset<long> sumSeen;
                sumSeen.insert(sum);
                for(int r=0;r<rows;++r){
                    rowsum[r] = matrix[r][c1] - ((c2-1)>=0? matrix[r][c2-1]:0); 
                    sum += rowsum[r];
                    result+=sumSeen.count(sum-target);
                    sumSeen.insert(sum);
                } 
            }
        return result;
    }
};