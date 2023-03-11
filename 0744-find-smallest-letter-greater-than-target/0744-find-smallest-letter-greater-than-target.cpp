class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res='#';
        int n=letters.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(letters[mid]==target)
                low=mid+1;
            else if(letters[mid]>target)
            {
                res=letters[mid];
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        if(res=='#')
            return letters[0];
        
        return res;
    }
};