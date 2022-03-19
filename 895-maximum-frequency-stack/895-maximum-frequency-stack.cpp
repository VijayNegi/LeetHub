class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> stk;
    int maxfreq{0};
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        stk[++freq[val]].push(val);
        maxfreq = max(freq[val],maxfreq);
    }
    
    int pop() {
        int val= stk[maxfreq].top();
        stk[maxfreq].pop();
        freq[val]--;
        if(stk[maxfreq].empty())
            --maxfreq;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */