class Solution {
public:
     int t[2002][2002];
     bool isPalindrome(string &s, int start, int end) {
        
        while(start <= end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    int solve(string &s, int i, int j)
    {
        if(i>=j) t[i][j]= 0;
        if(isPalindrome(s,i,j)==true)
            return 0;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            if(isPalindrome(s,i,k)==true)
             {
            int temp=solve(s,i,k)+solve(s,k+1,j)+1;
            ans=min(ans,temp);
             }
        }
        return t[i][j]=ans;
        
    }
    int minCut(string s) {
        int i=0,j=s.length()-1;
       
      memset(t,-1,sizeof(t));
     int res=solve(s,i,j);
        return res;
        
    }
};