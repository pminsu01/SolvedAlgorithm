class Solution {
    public int lengthOfLongestSubstring(String s) {
        
       
        int max = 0;
        int index =0;
        
        Set<Character> set = new HashSet<>();
        
        for(int i = 0; i < s.length(); i++) {
            char curchar = s.charAt(i);
            
            while(set.contains(curchar)){
                set.remove(s.charAt(index++));
            }
            
            
            set.add(curchar);
            max = Math.max(set.size(),max);
        
        }
        
        return max;
    }
}

