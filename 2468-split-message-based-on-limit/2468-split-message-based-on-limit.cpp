class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<string> result;
        int n = message.size();
        //cout<<"n="<<n<<endl;
        int suffixLen = 3; // without digits
        int maxSegment = 0;
        int extraDigits = 0;
        int digit = 1;
        while(digit < 5){
            suffixLen += 2; // add new digits
            if(limit <= suffixLen)
                return result;
            maxSegment = maxSegment*10+9;
            //cout<<digit<<" "<<suffixLen<<" "<<maxSegment<<endl;
            // check if string can be fit in given digit segment length
            if(limit*maxSegment - (suffixLen*maxSegment - extraDigits) >= n) 
            {
                int pos = 0;
                int seg = 1;
                while(pos<n) {
                    string temp = "<"+to_string(seg)+"/"+ to_string(maxSegment)+ ">";
                    int r = limit - temp.size();
                    temp = message.substr(pos,r)+ temp;
                    result.push_back(temp);
                    pos +=r;
                    ++seg;
                }
               
                string s = to_string(--seg);
                for(auto& r:result)
                    r.replace(r.size()-(digit+1),digit,s);

                return result;
            }
            extraDigits += maxSegment;
            ++digit;
        }
        return result;
    }
};