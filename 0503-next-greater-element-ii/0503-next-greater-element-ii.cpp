class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
           vector<int> v;
        stack<int>s;
        for(int i=2*n-1;i>=0;i--)
        {
         while(s.empty()==false && s.top()<=nums[i%n])
                    s.pop();
            if(i<n)
            {
                if(s.empty()==false)
                  v.push_back(s.top());
                else
                  v.push_back(-1);    
            }
            s.push(nums[i%n]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};