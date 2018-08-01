class Solution {
    public int[][] flipAndInvertImage(int[][] A) 
    {
        int length = A.length;
        int width = A[0].length;
        int[][] arr = new int[length][width];
        
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr[i][j] = A[i][width-j-1];
            }
        }
        
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = 1;
                }
            }
        }
        return arr;
    }
}
