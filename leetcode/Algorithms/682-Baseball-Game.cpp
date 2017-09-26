class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int _size = ops.size();
        int ans = 0;
        int x, y;
        
        for(int i=0; i<_size; ++i){
            if(ops[i] == "+"){
                x = st.top();
                st.pop();
                y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else if(ops[i] == "D"){
                st.push(st.top()*2);
            }
            else{
                x = atoi(ops[i].c_str());
                st.push(x);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

