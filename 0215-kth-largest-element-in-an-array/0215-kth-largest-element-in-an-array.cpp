class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater <>());
       
        int ans = nums.at(k - 1);

        return ans;
    }
};