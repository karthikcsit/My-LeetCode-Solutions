class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>l;
        vector<int>ans;
        int i=0,j=0;
        while(j<nums.size())
        {
          // l.push_back(nums[j]);
            while(l.back()<nums[j] &&l.size()>0)
            {   
                l.pop_back();
            }
           l.push_back(nums[j]);
            
            if(j-i+1<k)
                j++;
            
            else if(j-i+1==k)
            {
                ans.push_back(l.front());
                if(l.front()==nums[i])
                    l.pop_front();
                i++;
                j++;
            }
        }
        return ans;
        
    }
};