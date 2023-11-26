class Solution
{
public:
    long long beautifulSubstrings(string s, int k)
    {
        int V=0, C=0;
        vector<int> diff{0};

        // prefix of differences for seen vowels and seen consonants
        for (char ch : s)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                V += 1;
            }
            else{
                C += 1;
            }
            diff.push_back(V - C);
        }

        // count subsequences using hashing of seen differences
        unordered_map<int, vector<int>> pos;
        int count = 0;
        for (int i = 0; i < diff.size(); ++i)
        {
            int d = diff[i];
            if (pos.find(d) != pos.end())
            {
                for (int j : pos[d])
                {
                    long t = (i - j) / 2;
                    if (t*t % k == 0) count += 1;
                }
            }
            pos[d].push_back(i);
        }

        return count;       
    }
};