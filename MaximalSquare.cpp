class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.size() == 0)
        {
            return 0;
        }
        std::vector< std::vector< int > > sums( matrix.size()+1, std::vector<int> ( matrix[0].size()+1, 0 ) );
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {   
                    //sums[i][j] = min(min(sums[i-1][j], sums[i][j-1]), sums[i-1][j-1]) + 1; 
                    sums[i+1][j+1] = min(min(sums[i][j+1], sums[i+1][j]), sums[i][j]) + 1;
                }
            }
        }
        
        int max = 0;
        
        for (int i = 0; i < sums.size(); i++)
        {
            for (int j = 0; j < sums[0].size(); j++)
            {
                if (sums[i][j] > max)
                {
                    max = sums[i][j];
                }
            }
        }
        return max*max;
    }
};
