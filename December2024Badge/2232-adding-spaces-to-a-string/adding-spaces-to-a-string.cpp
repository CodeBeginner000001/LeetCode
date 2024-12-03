class Solution {
public:
   string addSpaces(string s, vector<int>& spaces) {
       int n = spaces.size();
        string newString="";
        int stringsize = s.size();
        int i=0;
        int j=0;
        while(j<n)
        {
            newString+=s.substr(i,spaces[j]-i)+" ";
            i = spaces[j];
            j++;
        }
        newString+=s.substr(i,stringsize);
        return newString;
    }
};