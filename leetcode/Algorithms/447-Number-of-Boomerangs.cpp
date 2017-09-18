#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/**
 * Title:447. Number of Boomerangs
    Given n points in the plane that are all pairwise distinct,
    a "boomerang" is a tuple of points (i, j, k) such that the distance
    between i and j equals the distance between i and k (the order of the tuple matters).

    Find the number of boomerangs. You may assume that n will be at most 500
    and coordinates of points are all in the range [-10000, 10000] (inclusive).

    Example:
    Input:
    [[0,0],[1,0],[2,0]]

    Output:
    2

    Explanation:
    The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */

/** solution
    对于每一个点，都去遍历一下与其他点的长度，然后在相同长度中选择 C(2,num) 即num*(num-1) (num>2)
    然后将这些值累加起来
 */



/*************************** Submit Part *****************************/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
        map<int, int> mp;
        int ans = 0;
        int _size = points.size();
        int i,j;
        int dis;
        for(i=0; i<_size; ++i){
            for(j=0; j<_size; ++j){
                dis = distance_between_points(points[i], points[j]);
                if(mp.find(dis)!=mp.end()) mp[dis]++;
                else mp[dis]=1;
            }
            map<int,int>::iterator it;
            for(it=mp.begin(); it!=mp.end(); ++it){
                ans += count_num_of_way(it->second);
            }
            mp.clear();
        }

        return ans;
    }
private:
    int distance_between_points(pair<int,int> a, pair<int, int> b){
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }
    int count_num_of_way(int n){
        if(n<2) return 0;
        return n*(n-1);
    }
};
/*************************** Submit Part *****************************/

int main()
{
    vector<pair<int, int> > points;
    int x, y;
    while(cin >> x >> y){
        pair<int, int> tmp;
        tmp = make_pair(x,y);
        points.push_back(tmp);
    }
    Solution solution;
    cout << solution.numberOfBoomerangs(points) << endl;
    return 0;
}
