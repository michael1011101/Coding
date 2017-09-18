#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Title: 14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
 */

/** solution
    两两比较求出前缀
 */


/*************************** Submit Part *****************************/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        int _size = strs.size();
        if(_size==0) return "";
        string prefix = strs[0];
        for(i=1; i<_size; ++i){
            prefix = getCommonPrefix(prefix, strs[i]);
        }
        return prefix;
    }
private:
    string getCommonPrefix(string a, string b){
        int size1 = a.size();
        int size2 = b.size();
        int len = min(size1, size2);
        int i;
        for(i=0; i<len; ++i){
            if(a[i] != b[i]) break;
        }
        return a.substr(0, i);
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<string> strs;
    string s;
    while(cin >> s){
        strs.push_back(s);
    }
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}

