class Solution {
public:
    // https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/141768/Detailed-explanation-O(NlogN)
    // or https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/2433416/C%2B%2B-using-Priority-Queue-oror-Very-Simple-and-Easy-to-Understand-Solution
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
    }
};