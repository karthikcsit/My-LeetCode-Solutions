class Solution {
public:
    
int mySqrt(int x) {
       /* int l=1;
        long h=x;
        int ans=0;
        while(l<=h)
        {
            int m=(l+h)/2;
            long msq=m*m;
            if(msq==x)
                return m;
            else if(msq>x)
                h=m-1;
            else
            {
                l=m+1;
                ans=m;
            }
        }
        return ans;
    }*/
     long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
    }
};