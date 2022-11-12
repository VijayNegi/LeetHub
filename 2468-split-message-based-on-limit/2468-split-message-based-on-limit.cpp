class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<string> result;
        int n = message.size();
        cout<<"n="<<n<<endl;
        int d = 5;
        if(limit<6)
            return result;
        if(limit*9 - d*9 >= n) 
        {
            int l = 0;
            int seg = 1;
            while(l<n) {
                string temp = "<"+to_string(seg)+"/"+"9>";
                int r = limit - temp.size();
                temp = message.substr(l,r)+ temp;
                result.push_back(temp);
                l +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit -2;
            for(auto& r:result)
                r.replace(r.size()-2,1,s);

            return result;
        }
        d=6;
        if(limit<7)
            return result;
        if(limit*99 - (d*99 - 9) >= n) 
        {
            int l = 0;
            int seg = 1;
            while(l<n) {
                string temp = "<"+to_string(seg)+"/"+"99>";
                int r = limit - temp.size();
                temp = message.substr(l,r)+ temp;
                result.push_back(temp);
                l +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit - 3;
            for(auto& r:result)
                r.replace(r.size()-3,2,s);
            return result;
        }
        d=7;
        if(limit<10)
            return result;
        if(limit*999 - (d*999 - 9 - 99) >= n) 
        {
            int l = 0;
            int seg = 1;
            while(l<n) {
                string temp = "<"+to_string(seg)+"/"+"999>";
                int r = limit - temp.size();
                temp = message.substr(l,r)+temp;
                result.push_back(temp);
                l +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit - 4;
            for(auto& r:result)
                r.replace(r.size()-4,3,s);
            return result;
        }
        d=8;
        if(limit<12)
            return result;
        cout<<"check";
        //return result;
        if(limit*9999 - (d*9999 - 9 - 99 - 999) >= n) 
        {
            int l = 0;
            int seg = 1;
            while(l<n) {
                string temp = "<"+to_string(seg)+"/"+"9999>";
                int r = limit - temp.size();
                if(l>=n-1000) {
                    cout<<l<<"," <<r<<"\n";
                }
                temp = message.substr(l,r)+temp;
                result.push_back(temp);
                l +=r;
                ++seg;
                
            }
            string s = to_string(--seg);
            //int start = limit - 4;
            for(auto& r:result)
                r.replace(r.size()-5,4,s);
            return result;
        }
        return result;
    }
};