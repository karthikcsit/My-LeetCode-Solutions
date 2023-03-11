class Solution {
public:
    int findMin(vector<int>& nums) {
          int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] < nums[n - 1])
            return nums[0];
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (nums[mid] < nums[mid - 1])
                return nums[mid];   
            if (nums[low] < nums[mid])
                low = mid + 1;
            else if (nums[high] > nums[mid])
                high = mid - 1;
        }
        return -1;
    }
};