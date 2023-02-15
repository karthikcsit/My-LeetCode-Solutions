class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
        int r=matrix.size(),c=matrix[0].size();
        int top=0,right=c-1,bot=r-1,left=0;
        while(top<=bot && left<=right)
        {
            for(int i=left;i<=right;i++)
                res.push_back(matrix[top][i]);
            top++;
             for(int i=top;i<=bot;i++)
                res.push_back(matrix[i][right]);
            right--;
            if(top<=bot)
            {
                 for(int i=right;i>=left;i--)
                res.push_back(matrix[bot][i]);
            bot--;
            }
            if(left<=right)
            {
                 for(int i=bot;i>=top;i--)
                res.push_back(matrix[i][left]);
            left++;
            }
        }
        return res;
        
    }
};