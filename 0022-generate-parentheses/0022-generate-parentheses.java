class Solution 
{
    public List<String> generateParenthesis(int n) 
    {
        List<String> list=new ArrayList<>();
    private boolean isValid(String str){
        Stack<Character> s=new Stack<>();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='('){
                s.push('(');
            }
            else if(!s.isEmpty() && str.charAt(i)==')'){
                s.pop();
            }
            else return false;
        }
        return s.isEmpty()==true;
    }
    private void solve(StringBuilder sb,int n){
        if(sb.length()==2*n){
            String str=sb.toString();
            if(isValid(str)){
                list.add(sb.toString());
            }
            return ;
        }
        sb.append("(");
        solve(sb,n);
        sb.deleteCharAt(sb.length()-1);
        sb.append(")");
        solve(sb,n);
        sb.deleteCharAt(sb.length()-1);
    }
    public List<String> generateParenthesis(int n) {
        solve(new StringBuilder(),n);
        return list;
    }
}