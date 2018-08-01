class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector < vector < int > > matrix(word1.size()+1, vector< int >(word2.size()+1,0));
        //matrix[0][0] = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = i; 
        }
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[0][j] = j; 
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                int addition;
                if (word1[i-1] == word2[j-1])
                {
                    matrix[i][j] = matrix[i-1][j-1];
                }
                else
                {
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1]))+1;
                }
            }
        }
        return matrix[matrix.size()-1][matrix[0].size()-1];
    }
};
