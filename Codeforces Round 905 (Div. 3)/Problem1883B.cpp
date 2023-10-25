/*
https://codeforces.com/contest/1883/problem/B
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
    while(t--){
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        vector<int> alphabetCount(26, 0); // maintain count of each alphabet
        for(int i = 0; i < n; i++) alphabetCount[s[i]-'a']++;
        // we have to pick n-k from alphabetCount
        int finalStringLength = n-k;
        int len = finalStringLength;
        // for odd: pick one char of odd count and rest of even count
        if(finalStringLength%2){
            int odd_count = 0;
            for(int i = 0; i < 26; i++){
                int a = alphabetCount[i];
                if(a%2 && odd_count == 0){
                    len -= a;
                    odd_count++;
                }
                else if(a%2 && odd_count != 0 && a > 2){
                    len -= (a-1);
                }
                else if(a%2 == 0){
                    len -= a;
                }
 
                if(len > 0) continue;
                else break;
            }
            if(len <= 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        // for even: pick all even count chars
        else{
            for(int i = 0; i < 26; i++){
                int a = alphabetCount[i];
                if(a%2 == 0){
                    len -= a;
                }
                else if(a%2 && a>2){
                    len -= (a-1);
                }
 
                if(len > 0) continue;
                else break;
            }
            if(len <= 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
 
 
    }
    return 0;
}