class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        //vector<int> instk(1001,0);
        int n = pushed.size();
        int pu,po;
        pu=po=0;
        while(pu<pushed.size() && po<popped.size())
        {
            while(!stk.empty())
            {
                if(stk.top() == popped[po])
                {
                    //cout<<"po="<<popped[po]<<endl;
                    stk.pop();
                    po++;
                }
                else
                    break;
            }
            //cout<<"pu="<<pushed[pu]<<endl;
            stk.push(pushed[pu++]);  
        }
        
        while(!stk.empty())
        {
                if(stk.top() == popped[po])
                {
                    //cout<<"po="<<popped[po]<<endl;
                    stk.pop();
                    po++;
                }
                else
                    break;
        }
        
        return stk.empty() && (pu>=n);
    }
};