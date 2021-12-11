class Solution {
    public int reverse(int x) {
        
        String str = String.valueOf(x);
        String resultStr ="";
        
        String answer ="";
        
        boolean minusflag = false;
        
        if(str.charAt(0) == '-') {
            minusflag = true; // minus 일 때 체크
            str = str.substring(1); // -를 제외한 substring
        }
        
        for(int i=str.length()-1; i >=0; i--){
            resultStr += String.valueOf(str.charAt(i));
        }
        
        Long resultLong = Long.parseLong(resultStr);
        if(minusflag) resultLong *= -1;
        
        if(resultLong > Integer.MAX_VALUE || resultLong < Integer.MIN_VALUE) { return 0; } // max값 범위 체크

        return resultLong.intValue();
        
    }
}