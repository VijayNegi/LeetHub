class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(),courses.end(),[](vector<int>& left, vector<int>& right){if(left[1]==right[1]) return left[0]<right[0]; return left[1]<right[1];});
        priority_queue<int> pq;
        int curr_day=0;
        int result=0;
        for(int i=0;i<n;++i) {
            if(curr_day+courses[i][0] <= courses[i][1] ) {
                pq.push(courses[i][0]);
                curr_day+= courses[i][0];
                ++result;
            }
            else if(pq.size() && (pq.top()>courses[i][0]) && (curr_day - pq.top() + courses[i][0] <= courses[i][1])) {
                curr_day -= pq.top() - courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }   
        }
        return result;
    }
};