#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Title:56. Merge Intervals
    Given a collection of intervals, merge all overlapping intervals.

    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].
 */

/** solution
    模拟
    另外原来在类中写cmp函数 需要加上static修饰
 */



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
/*************************** Submit Part *****************************/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool cmp(Interval a, Interval b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }

    Interval merge2Interval(Interval a, Interval b){
        int x = min(a.start, b.start);
        int y = max(a.end, b.end);
        return Interval(x,y);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int m = intervals.size();
        if(m==0) return vector<Interval>();
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval interval = intervals[0];
        for(int i=1; i<m; ++i){
            Interval tmp = intervals[i];
            if(tmp.start <= interval.end)
                interval = merge2Interval(interval, tmp);
            else{
                ans.push_back(interval);
                interval = tmp;
            }
        }
        ans.push_back(interval);

        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<Interval> intervals;
    int m,n;
    while(cin>>m>>n){
        intervals.push_back(Interval(m,n));
    }

    Solution solution;
    vector<Interval> result;
    result = solution.merge(intervals);
    for(vector<Interval>::iterator it=result.begin(); it!=result.end(); ++it){
        Interval interval = *it;
        cout << interval.start << ' ' << interval.end << endl;
    }
    return 0;
}
