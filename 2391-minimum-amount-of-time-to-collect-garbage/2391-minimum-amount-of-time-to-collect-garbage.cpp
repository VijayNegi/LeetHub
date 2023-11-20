class Solution {
public:
    int garbageCollection1(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        function<int(char)> collectionTime = [&](char c){
            int currentCost=0;
            int finalCost = 0;
            for(int i=0;i<=n;++i){
                int num_items = std::count(garbage[i].begin(), garbage[i].end(), c);
                if(num_items){
                    currentCost+=num_items;
                    finalCost = currentCost;
                }
                if(i<n)
                    currentCost += travel[i];
            }
            return finalCost;
        };
        int result = collectionTime('M');
        result += collectionTime('P');
        result += collectionTime('G');
        return result;
    }
    // other solution from commetns
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int len = garbage.size();
        int res = 0;
        unordered_set<char> s;
        for (int i = len - 1; i >= 0 ; i--) {
            for (char ch : garbage[i]) 
                if (!s.count(ch)) 
                    s.insert(ch);

            res += garbage[i].length();
            res += i > 0 ? s.size() * travel[i - 1] : 0;
        }

        return res;
    }
};