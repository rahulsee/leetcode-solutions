// https://leetcode.com/problems/complex-number-multiplication

class Solution {
    public String complexNumberMultiply(String a, String b) {
        String aa[]=a.split("\\+");
        String bb[]=b.split("\\+");
        int ar=Integer.parseInt(aa[0]);
        int ai=Integer.parseInt(aa[1].substring(0,aa[1].length()-1));
        int br=Integer.parseInt(bb[0]);
        int bi=Integer.parseInt(bb[1].substring(0,bb[1].length()-1));
        int cr=ar*br-ai*bi;
        int ci=ar*bi+ai*br;
        return String.valueOf(cr)+"+"+String.valueOf(ci)+"i";
    }
}