#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])){
                count++;
            }        
        }
        maxi = max(maxi, count);
        for(int j = k; j<s.size(); j++){
            if(isVowel(s[j])){
                count++;
            }
            if(isVowel(s[j-k])){
                count--;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};