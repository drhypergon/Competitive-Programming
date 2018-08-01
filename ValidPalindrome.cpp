class Solution {
    public boolean isPalindrome(String s) 
    {
        String revised = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        String revised1 = new StringBuffer(revised).reverse().toString();
        
        System.out.println(revised);
        System.out.println(revised1);

        if (revised.equals(revised1))
        {
            return true;
        }
        return false;
    }
}
