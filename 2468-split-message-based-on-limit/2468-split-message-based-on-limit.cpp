class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<string> result;
        int n = message.size();
        //cout<<"n="<<n<<endl;
        int suffixLen = 5;
        if(limit <= suffixLen)
            return result;
        // check if string can be fit in 1-9 segment range i.e. single digit segment length
        // max chars - suffix
        if(limit*9 - suffixLen*9 >= n) 
        {
            int pos = 0;
            int seg = 1;
            while(pos<n) {
                string temp = "<"+to_string(seg)+"/"+"9>";
                int r = limit - temp.size();
                temp = message.substr(pos,r)+ temp;
                result.push_back(temp);
                pos +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit -2;
            for(auto& r:result)
                r.replace(r.size()-2,1,s);

            return result;
        }
        // check if string can be fit in 1-99 segment range i.e. two digit segment length
        suffixLen = 7;
        if(limit <= suffixLen)
            return result;
        
        if(limit*99 - (suffixLen*99 - 9) >= n) 
        {
            int pos = 0;
            int seg = 1;
            while(pos<n) {
                string temp = "<"+to_string(seg)+"/"+"99>";
                int r = limit - temp.size();
                temp = message.substr(pos,r)+ temp;
                result.push_back(temp);
                pos +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit - 3;
            for(auto& r:result)
                r.replace(r.size()-3,2,s);
            return result;
        }
        // check if string can be fit in 1-999 segment range i.e. three digit segment length
        suffixLen = 9;
        if(limit <= suffixLen)
            return result;
        
        if(limit*999 - (suffixLen*999 - 9 - 99) >= n) 
        {
            int pos = 0;
            int seg = 1;
            while(pos<n) {
                string temp = "<"+to_string(seg)+"/"+"999>";
                int r = limit - temp.size();
                temp = message.substr(pos,r)+temp;
                result.push_back(temp);
                pos +=r;
                ++seg;
            }
            string s = to_string(--seg);
            int start = limit - 4;
            for(auto& r:result)
                r.replace(r.size()-4,3,s);
            return result;
        }
        
        // check if string can be fit in 1-9999 segment range i.e. four digit segment length
        suffixLen = 11;
        if(limit <= suffixLen)
            return result;
        
        if(limit*9999 - (suffixLen*9999 - 9 - 99 - 999) >= n) 
        {
            int pos = 0;
            int seg = 1;
            while(pos<n) {
                string temp = "<"+to_string(seg)+"/"+"9999>";
                int r = limit - temp.size();
                temp = message.substr(pos,r)+temp;
                result.push_back(temp);
                pos +=r;
                ++seg;
            }
            string s = to_string(--seg);
            for(auto& r:result)
                r.replace(r.size()-5,4,s);
            return result;
        }
        return result;
    }
};