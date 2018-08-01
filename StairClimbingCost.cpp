class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> result(cost.size());
        result[0] = cost[0];
        result[1] = cost[1];
        
        
        for (int i = 2; i < result.size(); i++)
        {
            result[i] = cost[i];
        }
        
        //result[result.size()-1] = 0;
        for (int i = 2; i < result.size(); i++)
        {
            result[i] += min(result[i-1],result[i-2]);
        }
        return min(result[result.size()-1], result[result.size()-2]);
    }
    
};
