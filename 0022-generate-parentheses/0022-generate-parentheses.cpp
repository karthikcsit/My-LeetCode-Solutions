class Solution {
public:
   vector<string> generateParenthesis(int n) {
         vector<string>v;
        string op="";
        int open =n;
        int close=n;
        solve(op,open,close,v);
        return v;
    }
    void solve( string op,int open,int close, vector<string>&v)
    {
        if(open==0 && close==0)
        {
            v.push_back(op);
            return;
        }
        if(open!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(op1,open-1,close,v);
        }
        if(close>open)
        {
            string op2=op;
            op2.push_back(')');
             solve(op2,open,close-1,v);
        }
        return;
    }
};