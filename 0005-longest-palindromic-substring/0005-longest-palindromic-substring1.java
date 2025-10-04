class Solution {
    private boolean isPalindrome(String s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s.charAt(i)!=s.charAt(n-1-i)){
                return false;
            }
        }
        return true;
    }
    public String longestPalindrome(String s) {
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<s.length();i++){
            for(int j=i+sb.length()+1;j<s.length()+1;j++){
                if(isPalindrome(s.substring(i,j))){
                    sb=new StringBuilder(s.substring(i,j));
                }
            }
        }
        return sb.toString();
    }
}
