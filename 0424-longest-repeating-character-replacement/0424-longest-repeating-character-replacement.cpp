class Solution {
public:
    int characterReplacement(string s, int k) {
         int i=0,j=0;
      
        int n=s.size();
       map<char,int>mp;
        int maxfre=0;
        int res=-1;
        while(j<n)
        {
            mp[s[j]]++;
            maxfre=max(maxfre,mp[s[j]]);
          
                
         /*  if((j-i+1)-maxfre<k)
               j++;*/
           if((j-i+1)-maxfre<=k)
           {
               res=max(res,j-i+1);
               j++;
           }
           else if((j-i+1)-maxfre>k)
           {
               while((j-i+1)-maxfre>k)
               {
                   mp[s[i]]--;
                      
                   i++;
               }
               j++;
            }
      
            
        }
       
        return res;
    }
};