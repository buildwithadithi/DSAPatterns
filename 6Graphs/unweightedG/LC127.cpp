#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;

        queue<pair<string, int>> q;

        q.push({beginWord, 0});
        visited.insert(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int transformations = q.front().second;
            q.pop();

            if (word == endWord)
                return transformations + 1;

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if (ch == word[i])
                        continue;

                    temp[i] = ch;

                    if (words.count(temp) && !visited.count(temp)) {

                        visited.insert(temp);
                        q.push({temp, transformations + 1});
                    }
                }
            }
        }

        return 0;
    }
};