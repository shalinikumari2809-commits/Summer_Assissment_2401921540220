class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> pCount(26, 0);
        vector<int> winCount(26, 0);

        for (int i = 0; i < m; i++) {
            pCount[p[i] - 'a']++;
            winCount[s[i] - 'a']++;
        }

        if (pCount == winCount)
            ans.push_back(0);
        for (int i = m; i < n; i++) {
            winCount[s[i] - 'a']++;      
            winCount[s[i - m] - 'a']--;   

            if (pCount == winCount)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
