class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int mx=0;
        unordered_map<int,int>mp;
        if(fruits.size()==1)
            return 1;
        while(j<fruits.size())
        {
            mp[fruits[j]]++;
          /*  if(mp.size()<2)
                j++;*/
            
             if(mp.size()<=2)
            {
                mx=max(mx,j-i+1);
                j++;
                
            }
            else if(mp.size()>2)
              {
                   while(mp.size()>2)
                 {        
                   mp[fruits[i]]--;
                  if(mp[fruits[i]]==0)
                      mp.erase(fruits[i]);
                  i++;
                 } 
                j++;
              }
            
        }
      return mx;
        
    }
};