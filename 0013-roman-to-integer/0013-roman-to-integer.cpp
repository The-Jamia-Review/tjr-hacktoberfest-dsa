class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            
           ans+=m[ch];
             if(i>0&&(ch=='V'||ch=='X')&&s[i-1]=='I')
              ans-=2;
             else  if(i>0&&(ch=='L'||ch=='C')&&s[i-1]=='X')
              ans-=20;
             else  if(i>0&&(ch=='D'||ch=='M')&&s[i-1]=='C')
              ans-=200;
              

        }
        return ans;
    }
};