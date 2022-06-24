typedef long long ll;
class Solution {
public:
    bool isPossible1(vector<int>& target) {
        int n = target.size();
        if(n==1 && target[0]!=1)
            return false;
        priority_queue<int> pq(target.begin(),target.end());
        long sum = accumulate(target.begin(),target.end(),0);
        
        while(pq.top()>1) {
            sum -= pq.top(); 
            if(pq.top()<=sum) return false;
            int val = pq.top() % sum; // new element
            sum += val;
            if(val > 0) {
                //sum -= pq.top() - val;
                pq.pop();
                pq.push(val);
                //sum += val;
            }
            else
                return false;
        }
        return true;
    }
    bool isPossible(vector<int>& target) {
        bool result = true;
        int len = target.size();
        if(len==1 && target[0]!=1)
            return false;
            
        make_heap(target.begin(),target.end());
        ll sum = 0;
        sum = std::accumulate(target.begin(), target.end(), sum);
        while(true)
        {
            sum -= target.front(); 
            if(target.front()==1 || sum==1)
                break;
            
            if(target.front()<=sum)
            {
                result = false;
                break;
            }
            
            int diff = target.front() % sum; // new element
            sum += diff;
            if(diff<1)
            {
                result = false;
                break;
            }
            pop_heap(target.begin(),target.end());
            target[len-1] = diff;
            push_heap(target.begin(),target.end());
        }
        return result;
    }
};