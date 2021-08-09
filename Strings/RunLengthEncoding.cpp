#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
   int count = 1;
   string output = "";
  for(int i=1;i<str.length();i++){
      if(str[i-1]==str[i]){
          count++;
      }else{
          if(count==0){
              output += str[i-1];
          }
          output += str[i-1]+to_string(count);
          count = 1;
      }
  }
  output += str[str.length()-1]+to_string(count);
  if(output.length()>str.length()){
      return str;
  }
    
   return output;
}
