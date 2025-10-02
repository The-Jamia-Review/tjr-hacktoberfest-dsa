class Solution {
public:
    void GenerateParenthes(int open,int close,int n,string s,vector<string>&v){
        if(open==close&&open+close==n*2){
            v.push_back(s);
            return;
        }
        if(open<n){
            GenerateParenthes(open+1,close,n,s+"(",v);
        }
        if(close<open){
            GenerateParenthes(open,close+1,n,s+")",v);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>v;
        int close=0,open=0;
        GenerateParenthes(open,close,n,s,v);
        return v;
    }
};