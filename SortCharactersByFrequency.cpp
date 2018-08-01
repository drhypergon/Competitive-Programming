class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> elems;
        priority_queue<pair<int, char>> q;
        
        for (int i = 0; i < s.size(); i++)
        {
            elems[s[i]]++;
        }
        
        for (auto it = elems.begin(); it != elems.end(); ++it)
        {
            pair<int, char> p(it->second, it->first);
            q.push(p);
        }
        string result = "";
        while (!q.empty())
        {
            pair<int, char> val = q.top();
            q.pop();
            
            for (int j = 0; j < val.first; j++)
            {
                result.push_back(val.second);
            }
        }
        return result;
        
    }
};
