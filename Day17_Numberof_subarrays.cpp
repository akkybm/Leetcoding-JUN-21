class Solution {
public:
    int countsubarrays(int n)
    {
        return n*(n+1)/2;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res=0;
        int g_right = 0;      // number of elements smaller than or equal to right;
        int s_left = 0;      // number of element smaller than left;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] > right)
            {
                res += (countsubarrays(g_right) - countsubarrays(s_left));
                g_right = 0;
                s_left = 0;
            }
            
            else if(nums[i] < left)
            {
                g_right++;
                s_left++;
            }
            
            else
            {
                res -= countsubarrays(s_left);
                s_left=0;
                g_right++;
            }
        }
        
        res += (countsubarrays(g_right) - countsubarrays(s_left));
        return res;
    }
};
