class Solution {
public:
   // int t[1001][1001];
    string lcs(string str1, string str2,int m,int n) {
        
        
       int t[m+1][n+1];
         for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
                if(i==0||j==0)
                    t[i][j]=0;
        
         for(int i=1;i<m+1;i++)
         {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                    t[i][j]= 1+  t[i-1][j-1];
                
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
         }
         
          int i=m,j=n;
        string s="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                {
                     s.push_back(str1[i-1]);
                    i--;
                }
                else 
                {
                     s.push_back(str2[j-1]);
                    j--;
                }
             }
        }
        while(i>0)
        {
            s.push_back(str1[i-1]);
                    i--; 
        }
        while(j>0)
        {
              s.push_back(str2[j-1]);
                    j--;
        }
        reverse(s.begin(),s.end());
        return s;
        
                

        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
      string s1=  lcs(str1,str2,m,n);
       return s1;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  /*  string LCS(string str1, string str2,int m,int n){
string s="";
int t[m+1][n+1];
for(int i=0;i<m+1;i++){
for(int j=0;j<n+1;j++){
if(i==0 || j==0){
t[i][j]=0;
}
}
}
for(int i=1;i<m+1;i++){
for(int j=1;j<n+1;j++){
if(str1[i-1]==str2[j-1]){
t[i][j]=1+t[i-1][j-1];
}
else{
t[i][j]=max(t[i-1][j],t[i][j-1]);
}
}
}
int i=m;
int j=n;
while(i>0 && j>0){
if(str1[i-1]==str2[j-1]){
s.push_back(str1[i-1]);
i--;
j--;
}
else if(t[i-1][j]>t[i][j-1]){
s.push_back(str1[i-1]);
i--;
}
else{
s.push_back(str2[j-1]);
j--;
}
}
while(i>0){
s.push_back(str1[i-1]);
i--;
}
while(j>0){
s.push_back(str2[j-1]);
j--;
}
reverse(s.begin(),s.end());
return s;

}
string shortestCommonSupersequence(string str1, string str2) {
    int m=str1.size();
    int n=str2.size();
    string ans=LCS(str1,str2,m,n);
    return ans;
    

}*/
};