class Solution {
public:
   
vector<int> nsl(vector<int>& heights, vector<int>&left,int n)
{
      
        int pseudopos=-1;
       
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            if(s.size()==0) 
                left.push_back(pseudopos);
            else if(s.size()>0 && s.top().first<heights[i])
                left.push_back( s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.size()==0) left.push_back(pseudopos);
                else
                   left.push_back( s.top().second); 
            }
            s.push({heights[i],i});
        }
    return left;
}       
 vector<int> nsr(vector<int>& heights,vector<int>&right,int n)  
  {    
        int pseudopos=n;
      
        stack<pair<int,int>>st;
         for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0) right.push_back(pseudopos);
            else if(st.size()>0 && st.top().first<heights[i])
                right.push_back( st.top().second);
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                if(st.size()==0) 
                    right.push_back(pseudopos);
                else
                   right.push_back( st.top().second); 
            }
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
          return right;
 }
     int largestRectangleArea(vector<int>& heights) 
     {
          int n=heights.size();
          vector<int>left;
         vector<int>right;
         nsl( heights,left,n);
         nsr( heights,right,n);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
         int   z=heights[i]* (right[i]-left[i]-1);
            ans.push_back(z);
        }
         sort(ans.begin(),ans.end());
       
        return ans[heights.size()-1];
     }
};