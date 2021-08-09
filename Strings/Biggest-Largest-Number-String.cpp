#include<algorithm>
class Solution {
public:
 static  bool compare(string a,string b){
    return (a+b) > (b+a);
}
    string largestNumber(vector<int>& numbers) {
         vector<string> v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(),v.end(),compare);
    string s = "";
        for(int i=0;i<v.size();i++){
            s += v[i];
    }
   while(s.size() > 1 && s[0] == '0')
            s.erase(s.begin());
        
        return s;
    }
};
