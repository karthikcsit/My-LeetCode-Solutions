class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int r=matrix.size(),c=matrix[0].size();
       int i=0,j=(r*c)-1;
        if( !matrix.size())
        {
            return false;
        }
        while(i<=j)
        {
            int mid=(i+(j-i)/2);
            if(matrix[mid/c][mid%c]==target)
                return true;
            else if(matrix[mid/c][mid%c]>target)
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    
    }
};