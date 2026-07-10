#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> mp;

        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (mp.count(t[i]))
            {
                mp[t[i]]--;
            }
            else
            {
                return false;
            }
            if (mp[t[i]] == 0)
            {
                mp.erase(t[i]);
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }
};
*/