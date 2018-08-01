class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string> q;
        unordered_map<string, int> depth;
        
        if (beginWord == endWord)
        {
            return 1;
        }
        
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        q.push(beginWord);
        depth[beginWord] = 1;
        
        while (!q.empty())
        {
            string current = q.front();
            q.pop();
            if (oneDiff(current, endWord))
            {
                return depth[current] + 1;
            }
            
            for (int i = 0; i < wordList.size(); i++)
            {
                if (oneDiff(wordList[i], current) && depth.find(wordList[i]) == depth.end())
                {
                    depth[wordList[i]] = depth[current] + 1;
                    q.push(wordList[i]);
                }
            }
        }
        return 0;
    }
    
    bool oneDiff(string a, string b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                diff++;
            }
            if (diff > 1)
            {
                return false;
            }
        }
        return (diff == 1);
    }
};
