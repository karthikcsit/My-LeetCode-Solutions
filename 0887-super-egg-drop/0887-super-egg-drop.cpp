class Solution {
public:
    int t[101][10001];
    int solve(int k, int n)
    {
        if(n==0|| n==1)return n;
        if(k==1) return n;
        if(t[k][n]!=-1)
            return t[k][n];
        int mn=INT_MAX;
       int left = 1, right = n;
        while(left <= right) {
            int i = left + (right - left) / 2;
            
            int low = solve(k-1, i-1);
            int high = solve(k, n-i);
            
            int temp = 1 + max(low, high);
            mn = min(mn, temp);
            if(low < high) left = i + 1;
            else right = i - 1;          
        }
        return t[k][n]=mn;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }
   
};