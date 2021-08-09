#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string breakPalindrome(string palindrome) {
    int len = palindrome.length();
    if(len<=1){
        return "";
    }
    int halfLen = len/2;
    for(int i=0;i<halfLen;i++){
        if(palindrome[i]>'a'){
            palindrome[i]='a';
            return palindrome;
        }
    }
    
    palindrome[len-1] = 'b';
    return palindrome;
    
    
        
}
