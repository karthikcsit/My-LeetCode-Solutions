class Solution {
public:
    int fun(string s,int k)
    {
        int i=0,j=0;
        int n=s.size();
        int size=0;
        map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            
            
            while(mp.size()>k)
           {
                  mp[s[i]]--;
                  if(mp[s[i]]==0)
                      mp.erase(s[i]);
                  i++;
           }
            size+=(j-i+1);
            j++;
            
                
         }
        return size;
    }
    
    int numberOfSubstrings(string s) {
        return fun(s,3)-fun(s,2);
    }
};