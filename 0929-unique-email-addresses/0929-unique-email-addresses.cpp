class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueMails;
        for(auto& mail:emails){
            auto pos = mail.find('@');
            string name = getName(mail.substr(0,pos));
            uniqueMails.insert(name + mail.substr(pos,mail.size()-pos-1));
        }
        return uniqueMails.size();
    }
    string getName(string&& local){
        int l=0,r=0,n=local.size();
        while(r<n){
            if(local[r]=='+') break;
            if(local[r]!= '.')
                local[l++] = local[r];
            ++r;
        }
        local.resize(l);
        return local;
    }
    
};