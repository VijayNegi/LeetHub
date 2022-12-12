class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> pick;
        int count = 0;
        int l=0,r=0,n=fruits.size();
        int result = 0;
        while(r<n){
            while(r<n && (count<3)){
                pick[fruits[r]]++;
                if(pick[fruits[r]]==1) ++count;
                ++r;
            }
            //cout<<l<<" "<<r<<" "<<count<<endl;
            if(count==3)
                result = max(result,r-l-1);
            else
                result = max(result,r-l);
            while(l<r && count>2){
                pick[fruits[l]]--;
                if(pick[fruits[l]]==0) --count;
                ++l;
            }
        }
        return result;
    }
};