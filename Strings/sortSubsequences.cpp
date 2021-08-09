#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//Sorted Subsequences
void subsequence(string s,string o,vector<string> &v){
    //Base Case
    if(s.size()==0){
        v.push_back(o);
        return ;
    }

    //Recursive Case
    char ch = s[0];
    string reduced_input = s.substr(1);

    //Includes 
    subsequence(reduced_input,o+ch,v);
    
    //Excludes
    subsequence(reduced_input,o,v);
}

bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2;
    }
    return s1.length()<s2.length();
}
int main(){
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    subsequence(s,output,v);
    sort(v.begin(),v.end(),compare);
    for(auto s:v){
        cout<<s<<",";
    }
    return 0;
    
}
