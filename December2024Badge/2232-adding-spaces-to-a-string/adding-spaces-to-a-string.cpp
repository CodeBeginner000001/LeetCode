class Solution {
public:
   string addSpaces(string s, vector<int>& spaces) {
        string newString="";
        int stringIndex=0;
        int arrayIndex=0;
        while(arrayIndex< spaces.size())
        {
            newString+=s.substr(stringIndex,spaces[arrayIndex]-stringIndex)+" ";
            stringIndex = spaces[arrayIndex];
            arrayIndex++;
        }
        newString+=s.substr(stringIndex,s.size());
        return newString;
    }
};