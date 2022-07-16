
class MyCalendarThree {
    map<int,int> timeline;
    int res{0};
public:
    MyCalendarThree() {
        timeline = {{-1, 0}};
    }
    
    int book1(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing=0,result=0;
        for(auto m:timeline) {
            result = max(result, ongoing += m.second);
        }
        return result;
    }
    //https://leetcode.com/problems/my-calendar-iii/discuss/176950/C++-Map-Solution-Fastest
    int book(int s, int e) {
        //map<int, int> count = {{-1, 0}};
        auto start = timeline.emplace(s, (--timeline.upper_bound(s))->second);
        auto end = timeline.emplace(e, (--timeline.upper_bound(e))->second);
        for (auto i = start.first; i != end.first; ++i)
            res = max(res, ++(i->second));
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */