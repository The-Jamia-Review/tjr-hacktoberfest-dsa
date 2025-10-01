
class Solution {

    int expand(String s, int start, int end){
        while(start>=0 && end<s.length() && s.charAt(start)==s.charAt(end)){
            start--;
            end++;
        }
        return end-start-1;
    }


    public String longestPalindrome(String s) {
        if(s==null||s.length()<2)
        return s;
        int start = 0;
        int end = 0;

        for(int i=0; i<s.length(); i++){
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i+1);
            int max = Math.max(len1, len2);

            if(max>end-start){
                start = i-(max-1)/2;
                end = i+max/2;
            }
        }
        return s.substring(start, end+1);
    }
    
    public static void main(String[] args){
        Solution sol = new Solution();
        String s1 = "babad";
        System.out.println(sol.longestPalindrome(s1));
        String s2 = "cbbd";
        System.out.println(sol.longestPalindrome(s2));

    }
}