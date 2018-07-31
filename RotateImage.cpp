class Solution {
    public void rotate(int[][] matrix) 
    {
        int[][] picture = new int[matrix.length][matrix[0].length];
        int rows = matrix.length;
        int columns = matrix[0].length;
        
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[0].length; j++)
            {
                picture[i][j] = matrix[columns-j-1][i];
            }
        }
        //matrix = picture;
        
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[0].length; j++)
            {
                matrix[i][j] = picture[i][j];
            }
        }
    }
}
