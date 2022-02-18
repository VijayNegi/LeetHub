class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> seen;
        string pass(n,'0'),result;
        result += pass;
        seen.insert(pass);
        int count = pow(k,n);
        for(int i=0;i<count;++i)
        {
            string pre = pass.substr(1);
            pre+= to_string(k-1);
            char &c = pre.back();
            for(;c>='0';--c)
            {
                if(!seen.count(pre))
                {
                    seen.insert(pre);
                    result.append(1,c);
                    pass = pre;
                    break;
                }
            }
        }
        return result;
    }
};