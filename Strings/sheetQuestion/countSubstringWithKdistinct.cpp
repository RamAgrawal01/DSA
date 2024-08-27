#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

   long long countSubstringsWithAtMostKDistinct(string s, int k) {
           long long int n = s.length();
            vector<int> mp(26,0);
            int count = 0;
         long long int ans = 0;
    
         long long int i = 0, j = 0;
    
        while (j < n) 
        {
            if (mp[s[j]-'a'] == 0) count++;
            
            mp[s[j]-'a']++;
            
            if (count >= k) 
            {
                ans += (n - j);  
    
                while (count >= k) 
                {
                    if (--mp[s[i++]-'a'] == 0) count--;
                    else ans += (n - j);
                }
            }
    
            j++;
        }
    
        return ans;
}
  
    long long int substrCount (string s, int k) {
        
         return countSubstringsWithAtMostKDistinct(s, k) - countSubstringsWithAtMostKDistinct(s, k + 1);
    }
int main(){
    
    string str = "abcabc";
    int k =2;
    int ans = substrCount(str,k);
    cout<<ans;

}