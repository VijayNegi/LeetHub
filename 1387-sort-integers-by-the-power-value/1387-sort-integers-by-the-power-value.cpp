// https://leetcode.com/problems/sort-integers-by-the-power-value/discuss/547055/C%2B%2B-4-ms-precompute-and-partial-sort
int comp[1001] = {0};
class Solution {
    int compute(int i) {
    return i < 2 ? 0 :
        1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
    }
public:
    int getKth(int lo, int hi, int k) {
        if (comp[2] == 0)
            for (auto i = 2; i <= 1000; ++i)
                comp[i] = compute(i);
        vector<int> sorted(hi - lo + 1);
        iota(begin(sorted), end(sorted), lo);
        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
            return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
        return sorted[k - 1];
    }
};