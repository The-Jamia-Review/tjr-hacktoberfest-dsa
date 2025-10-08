class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> m;
        m.insert(0);
        vector<pair<int,int>> edges;
        for(auto build:buildings){
            edges.push_back({build[0],-build[2]});
            edges.push_back({build[1],build[2]});
        }
        sort(edges.begin(),edges.end());
        vector<vector<int>> res;
        int pre=0,cur;
        for(auto edge:edges){
            if(edge.second<0)
                m.insert(-edge.second);
            else
                m.erase(m.find(edge.second));
            cur=*(m.rbegin());
            if(pre!=cur){
                res.push_back({edge.first,cur});
                pre=cur;
            }
        }
         return res;
    }
};