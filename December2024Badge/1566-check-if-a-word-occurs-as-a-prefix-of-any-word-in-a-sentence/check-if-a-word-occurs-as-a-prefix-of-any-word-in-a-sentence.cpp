class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream obj(sentence);
        string temp;
        int count=0;
        while(obj>>temp)
        {
            count++;
            if(temp.substr(0,searchWord.size())== searchWord){
                return count;
            }
        }
        return -1;
    }
};