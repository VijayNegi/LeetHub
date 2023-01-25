class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int result=node1<node2? node1:node2;
        if(node1==node2)
            return result;
        int n1 = node1,n2 = node2;
        unordered_set<int> s1{node1},s2{node2};
        while(edges[n1] >= 0 || edges[n2]>=0){
            if(edges[n1]>=0){
                s1.insert(edges[n1]);
                int t = n1;
                n1 = edges[n1];
                edges[t] = -1;
            }
            if(edges[n2]>=0){
                s2.insert(edges[n2]);
                int t = n2;
                n2 = edges[n2];
                edges[t] = -1;
            }
            if(s1.count(n2) && s2.count(n1)){
                return n1<n2? n1:n2;
            }
            else if(s1.count(n2) )
                return n2;
            else if(s2.count(n1))
                return n1;
            // else if(n1==n2)
            //     return n1;
        }
        return -1;
    }
};