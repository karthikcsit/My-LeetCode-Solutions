class Solution {
public:
   vector<string> letterCasePermutation(string s) {
        string op="";
        vector<string>v;
        solve(op,s,v);
        return v;
    }
    void solve(string op,string s, vector<string>&v)
    {
        if(s.length()==0)
        {
            v.push_back(op);
            return;
        }
      if(isalpha(s[0]))
      {
        string op1=op;
        string op2=op;
        op1.push_back( tolower(s[0]) );
         op2.push_back( toupper(s[0]) );
          s.erase(s.begin()+0);
          solve(op1,s,v);
           solve(op2,s,v);
      } 
      else
      {
          string op1=op;
          op1.push_back(s[0]);
          s.erase(s.begin()+0);
           solve(op1,s,v);
      }
    }
};