#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;

    int left = 0;
    int ans = 0;

    for(int right = 0; right < s.size(); right++) {

        while(st.count(s[right])) {//while window is invalid that it if it contains a duplicate character, loop until you dont find a duplicate.
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        ans = max(ans, right - left + 1);
    }

    return ans;
}