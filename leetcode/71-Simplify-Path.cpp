#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:71. Simplify Path
    Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
 */

/** solution
    /./     /
    /h      /h
    /.      /
    /..     /
    /...    /...
    /.ad    /.ad
    /..ad   /..ad

 */



/*************************** Submit Part *****************************/
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string str = "";
        stack<string> st;
        bool flag = false;
        int dot = 0;
        for(int i=0; i<len; ++i){
            if('/' == path[i]){
                if(2 == dot&&str.length()==2){
                    if(!st.empty())
                        st.pop();
                }
                else if(dot==1&&str.length()==1);
                else if(str.length()>0)
                    st.push(str);
                flag = false;
                dot = 0;
                str = "";
            }
            else{
                flag = true;
                if('.' == path[i]) dot++;
                str += path[i];
            }
        }
        if(2 == dot&&str.length()==2){
            if(!st.empty())
                st.pop();
        }
        else if(dot==1&&str.length()==1);
        else if(str.length()>0)
            st.push(str);

        if(st.empty()) return "/";
        vector<string> vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(), vec.end());
        string ans = "";
        for(vector<string>::iterator it=vec.begin(); it!=vec.end(); ++it){
            ans += "/" + *it;
        }
        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    string str;
    cin >> str;

    Solution solution;
    cout << solution.simplifyPath(str) << endl;
    return 0;
}
