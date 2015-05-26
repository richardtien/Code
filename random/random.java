/*
Given a string containing letter, digit, and other characters, write a function
to check palindrome for only letter and digit. The implementation need to be 
in-place, no extra memory is allowed to create another string or array. 
For example: 

"ABA" is palindrome 
"A!#A" is palindrome 
"A man, a plan, a canal, Panama!" is palindrome
*/



public static boolean isPalindrome(String str){
        if (str == null){
            return true;
        }
        for (int head = 0 , tail = str.length() -1 ; head < tail; head++, tail--){
            while(!Character.isLetterOrDigit(str.charAt(head)) && head < tail){
                head++;
            }
            while(!Character.isLetterOrDigit(str.charAt(tail)) && head < tail){
                tail--;
            }
            if (Character.toLowerCase(str.charAt(tail)) != 	Character.toLowerCase(str.charAt(head))){
                return false;
            }
        }
        return true;
    }
