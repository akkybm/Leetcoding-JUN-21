class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++)
        {
            pascals(i,res);
        }
        return res;
        
    }
    
    void pascals(int n, vector<vector<int>>& res)
    {
        vector<int> temp;
        if(n==0)
        {
            temp.push_back(1);
        }
        
        if(n>0)
        {
            long int N = n+1;
            long int C = 1;
            for(int i=1;i<=N;i++)
            {
                temp.push_back(C);
                C = C * (N-i) / i;
            }
            
        }
        res.push_back(temp);
    }
};
