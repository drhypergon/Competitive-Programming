class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        if (start == end)
        {
            return 1;
        }
        
        queue<string> q;
        unordered_map<string, int> depth;
        
        if (std::find(bank.begin(), bank.end(), end) == bank.end())
        {
            return -1;
        }
        
        q.push(start);
        depth[start] = 0;
        
        while (!q.empty())
        {
            string current = q.front();
            q.pop();
            
            if (oneCharDiff(current, end))
            {
                return depth[current] + 1;
            }
            
            for (int i = 0; i < bank.size(); i++)
            {
                if (oneCharDiff(current, bank[i]) && depth.find(bank[i]) == depth.end())
                {
                    q.push(bank[i]);
                    depth[bank[i]] = depth[current] + 1;
                }
            }
            
        }
        return -1;
    }
    
    bool oneCharDiff(string a, string b)
    {
        int diffs = 0;
        
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                diffs++;
            }
            if (diffs > 1)
            {
                return false;
            }
        }
        return (diffs == 1);
    }
};
