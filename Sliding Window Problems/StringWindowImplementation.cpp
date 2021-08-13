#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s,string p){
     //Array as a Freq Map or you can hashmap
     int FP[256] = {0};
     int FS[256] = {0};

     for(int i=0;i<p.length();i++){
         FP[p[i]]++;
     }

     //Sliding Window Algorithm
     int cnt = 0;
     int start = 0; //Left Contraction
     int start_idx = -1; //Start_idx for best window
     int min_so_far = INT_MAX; //Large Number
     int window_size;

     for(int i=0;i<s.length();i++){
         //Expand the window by including current character
         char ch=  s[i];
         FS[ch]++;

         //Count how many characters have been matched till now(String And Pattern)
         if(FP[ch]!=0 and FS[ch]<=FP[ch]){
             cnt+=1;
         }
         
         //Another String
         //If all characters of the patterns are found
         //in the current window then you can start contracting
         if(cnt==p.length()){
             //Start contracting from the left to remove unwanted characters
             while(FP[s[start]]==0 or FS[s[start]]>FP[s[start]]){
                 FS[s[start]]--;
                 start++;
             }

             //Note, the window size
             window_size = i-start+1;
             if(window_size<min_so_far){
                 min_so_far = window_size;
                 start_idx = start;
             }
         }
     }
     if(start_idx==-1){
         return "No window found!";
     }
     return s.substr(start_idx,min_so_far);
}

int main(){
    string s,p;
    cin>>s>>p;

    cout<<find_window(s,p)<<endl;
}
