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
 * Title:57. Insert Interval
    Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

    You may assume that the intervals were initially sorted according to their start times.

    Example 1:
    Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

/** solution
    方法1 将newInterval放入intervals中，重新排序，模拟
    方法2 直接模拟，每一次都判断新的newInterval是否有重合，
    最后，对几种情况进行讨论
    1，已经重合
    2，没有重合：2.1 与最后一个区间重合；2.2与最后一个区间不重合
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

    bool isOverlaps(Interval a, Interval b){
        if(a.start<=b.start&&a.end>=b.end) return true;
        if(a.start>=b.start&&a.end<=b.end) return true;
        if(a.start>=b.start&&a.start<=b.end) return true;
        if(b.start>=a.start&&b.start<=a.end) return true;
        return false;
    }

    Interval merge2Interval(Interval a, Interval b){
        int x = min(a.start, b.start);
        int y = max(a.end, b.end);
        return Interval(x,y);
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int m = intervals.size();
        vector<Interval> ans;
        if(m==0) {
            ans.push_back(newInterval);
            return ans;
        }

        bool flag = false;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval interval = intervals[0];
        for(int i=1; i<m; ++i){
            Interval tmp = intervals[i];
            if(!flag && isOverlaps(interval, newInterval)){
                interval = merge2Interval(interval, newInterval);
                flag = true;
            }

            if(tmp.start <= interval.end)
                interval = merge2Interval(interval, tmp);
            else{
                ans.push_back(interval);
                interval = tmp;
            }
        }

        if(!flag)
            if(isOverlaps(interval, newInterval)){
                interval = merge2Interval(interval, newInterval);
                ans.push_back(interval);
            }
            else{
                ans.push_back(interval);
                ans.push_back(newInterval);
                sort(ans.begin(), ans.end(), cmp);
            }
        else{
            ans.push_back(interval);
        }

        return ans;
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<Interval> intervals;
    int m,n;
    cin >> m >> n;
    Interval tmp = Interval(m,n);
    while(cin>>m>>n){
        intervals.push_back(Interval(m,n));
    }

    Solution solution;
    vector<Interval> result;
    result = solution.insert(intervals, tmp);
    for(vector<Interval>::iterator it=result.begin(); it!=result.end(); ++it){
        Interval interval = *it;
        cout << interval.start << ' ' << interval.end << endl;
    }
    return 0;
}
