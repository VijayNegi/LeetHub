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
    int kthGrammar3(int n, int k) {
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
    // ************
    // Iteration
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }

        // We assume the symbol at the target position is '1'.
        int symbol = 1;

        for (int currRow = n; currRow > 1; --currRow) {
            int totalElements = pow(2, (currRow - 1));
            int halfElements = totalElements / 2;

            // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
            if (k > halfElements) {
                // Flip the symbol.
                symbol = 1 - symbol;
                // Change the position after flipping.
                k -= halfElements;
            }
        }

        // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
        if (symbol != 0) {
            // Thus, the start symbol was '0' not '1'.
            return 0;
        } 

        // Start symbol was indeed what we started with, a '1'.
        return 1;
    }
    // math
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