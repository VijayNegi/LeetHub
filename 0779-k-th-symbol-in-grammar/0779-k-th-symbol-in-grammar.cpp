class Solution {
public:
    // self with help of editorial
    int kthGrammar1(int n, int k) {
        int len = pow(2,n-1);
        bool nan = false;
        while(n!=1){
            if(k>len/2){
                k -= len/2;
                nan = !nan;
            }
            else{
                len/=2;
                --n;
            }
        }
        return nan;
    }
    // BST traversal
    int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    int kthGrammar2(int n, int k) {
        return depthFirstSearch(n, k, 0);
    }
    // Normal recurson
    int kthGrammar(int n, int k) {
        // First row will only have one symbol '0'.
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // If the target is present in the right half, we switch to the respective left half symbol.
        if (k > halfElements) {
            return 1 - kthGrammar(n, k - halfElements);
        }

        // Otherwise, we switch to the previous row.
        return kthGrammar(n - 1, k);
    }
};
/*
0 -> 01
1 -> 10

0
01
0110
01101001
01101001 10010110
*/