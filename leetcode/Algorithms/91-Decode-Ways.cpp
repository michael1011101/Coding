ss Solution {
public:
    int numDecodings(string s) {
        //  "", "0", "0..."    return 0
        //  dp[i] = 0, if s[i]=='0' and s(i-1, i) not in [10, 26]
        //  dp[i] = dp[i-1], if s[i]=='0' and s(i-1, i) in [10, 26]
        //  dp[i] = dp[i-1], if s[i]!='0' and s(i-1, i) not in [10, 26]
        //  dp[i] = dp[i-1] + dp[i-2], if s[i]!='0' and s(i-1, i) in [10, 26]
        int len = s.length();
        if(len == 0)    return 0;
        if(s[0] == '0')   return 0;
        if(len == 1)    return 1;
            
        vector<int> dp(len+1, 0);
        dp[0] = dp[1] = 1;
        int tmp;
        for(int i=1; i<len; ++i){
            
            if(s[i] != '0') dp[i+1] = dp[i];
            else dp[i+1] = 0;
            
            tmp = (s[i-1]-'0')*10 + s[i]-'0';
            if(tmp>=10 && tmp<=26)  dp[i+1] += dp[i-1];
            
        }
        return dp[len];
    }
};

