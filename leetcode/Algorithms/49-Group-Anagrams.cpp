class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;
        string tmp;
        vector<vector<string> > ans;
        int _size = strs.size();
        
        sort(strs.begin(), strs.end());
        for(int i=0; i<_size; ++i){
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        
        for(map<string, vector<string> >::iterator it=mp.begin(); it!=mp.end(); ++it){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};

