class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> seen;
        
        string pass,result;
        pass.append(n,'0');
        
        result += pass;
        seen.insert(pass);
        int i=0,count = pow(k,n);
        char cc = '0' + k;
        while(i<count)
        {
            string pre = pass.substr(1);
            pre+= to_string(k-1);
            char &c = pre.back();
            for(;c>='0';--c)
            {
                //cout<< pre <<" ";
                if(!seen.count(pre))
                {
                    seen.insert(pre);
                    result.append(1,c);
                    pass = pre;
                    break;
                }
            }
            ++i;
            //cout<<endl;
        }
        
        return result;
    }
};