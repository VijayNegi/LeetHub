/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> idx;
    vector<vector<NestedInteger>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        //cout<<"\n update\n";
        //auto& curr = nestedList;
        stk.push_back(nestedList);
        idx.push_back(0);
        while(!stk.empty())
        {
            //cout<<"s="<<stk.back().size() <<" i="<<idx.back()<<endl;
            if(stk.back().size() <= idx.back())
            {
                //cout<<"pop\n";
                stk.pop_back();
                idx.pop_back();
                continue;
            }
            if(!(stk.back()[idx.back()].isInteger()))
            {
                //cout<<"getList\n";
                auto& curr = stk.back()[idx.back()].getList();
                stk.push_back(curr);
                ++idx.back();
                idx.push_back(0);
            }
            else 
                break;
        }
    }
    
    int next() {
        //cout<<"Next\n";
        int result = stk.back()[idx.back()].getInteger();
        ++idx.back();
        while(!stk.empty())
        {
            //cout<<"While\n";
            if(stk.back().size() <= idx.back())
            {
                
                stk.pop_back();
                idx.pop_back();
                continue;
            }
            if(!stk.back()[idx.back()].isInteger())
            { 
                auto& curr = stk.back()[idx.back()].getList();
                stk.push_back(curr);
                ++idx.back();
                idx.push_back(0);
            }
            else
                break;
        }
        return result;
    }
    
    bool hasNext() {
        //cout<<"hasNext\n";
        return stk.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */