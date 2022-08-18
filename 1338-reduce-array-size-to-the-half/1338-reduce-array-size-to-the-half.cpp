class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(begin(arr),end(arr));
        priority_queue<int> q;
        int pre = 0,count=0;;
        for(auto& n:arr) {
            if(pre == n)
                ++count;
            else {
                q.push(count);
                count=1;
                pre = n;
            }
        }
        q.push(count);
        
        int h = arr.size()/2;
        int result = 0;
        count=0;
        while(count<h) {
            count += q.top();
            q.pop();
            ++result;
        }
        return result;
    }
};