#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/**
 * Title:  125. Valid Palindrome
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    For example,
    "A man, a plan, a canal: Panama" is a palindrome.
    "race a car" is not a palindrome.

    Note:
    Have you consider that the string might be empty? This is a good question to ask during an interview.

    For the purpose of this problem, we define empty string as valid palindrome.
 */

/** solution

 */


/*************************** Submit Part *****************************/
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int left, right;
        left = 0, right = len-1;
        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;
            if(toupper(s[left++]) != toupper(s[right--])) return false;
        }
        return true;
    }
};
/*************************** Submit Part *****************************/

int main()
{

    return 0;
}
