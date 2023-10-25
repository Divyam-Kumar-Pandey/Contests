/*
https://codeforces.com/contest/1883/problem/A
*/
#include <bits/stdc++.h>
#define ONLINE_JUDGE
using namespace std;
 
 
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin >> t;
    int arr[] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    while(t--){
        int ans = 4;
        string s;
        cin >> s;
        ans += arr[s[0]-'0'];
        for(int i = 1; i < s.length(); i++){
            ans += abs(arr[s[i-1]-'0'] - arr[s[i]-'0']);
        }
        cout << ans << endl;
    }
    return 0;
}