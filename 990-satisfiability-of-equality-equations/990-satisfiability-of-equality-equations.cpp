struct DSU {
    vector<int> par;
    DSU(int k) {
        par.resize(k);
        iota(begin(par),end(par),0);
    }
    int parent(int id) {
         if(id == par[id])
             return id;
        return par[id] = parent(par[id]);
    }
    
    void merge(int id1,int id2) {
        int p1 = parent(id1);
        int p2 = parent(id2);
        par[p2] = p1;
    }
};
class Solution {
public:
    // DSU
    bool equationsPossible(vector<string>& equations) {
        DSU ds(26);
        for(auto e:equations) {
            if(e[1] == '=') 
                ds.merge(e[0]-'a', e[3]-'a');
        }
        for(auto e:equations) {
            if(e[1] == '!') 
                if(ds.parent(e[0]-'a') == ds.parent(e[3]-'a'))
                    return false;
        }
        return true;
    }
};