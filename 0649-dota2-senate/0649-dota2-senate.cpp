class Solution {
public:
    string predictPartyVictory(string senate) {
        int rd=0,rr=0;
        int s= senate.size();
        while(true){
            int l=0,r=0;
            int ss =s;
            while(r<ss){
                if(senate[r]=='R'){
                   if(rr) --rr,--s;
                    else {
                        senate[l++] = senate[r];
                        ++rd;
                    }
                }
                else{
                    if(rd) --rd,--s;
                    else {
                        senate[l++] = senate[r];
                        ++rr;
                    }
                }
                ++r;
            }
            if(ss ==s)
                break;
        }
        if(senate[0]=='R') return "Radiant";
        return "Dire";
    }
};