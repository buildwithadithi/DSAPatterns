#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    pair<int, int> expand(string s, int left, int right){

        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return {left+1, right-1};
    }
    string longestPalindrome(string s) {
        
        int st = 0;
        int e = 0;

        for(int i=0; i<s.size(); i++){

            pair<int, int> odd = expand(s, i, i);
            pair<int, int> even = expand(s, i, i+1);

            if(odd.second - odd.first > e-st){
                st = odd.first;
                e = odd.second;
            }

            if(even.second - even.first > e-st){
                st = even.first;
                e = even.second;
            }
        }
        return s.substr(st, e-st+1);
    }
};