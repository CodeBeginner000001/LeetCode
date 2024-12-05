class Solution {
public:
    bool canChange(string start, string target) {
         // Check if strings are of equal length
    if (start.size() != target.size()) {
        return false;
    }

    int Size = start.size();
    int i = 0, j = 0;

    while (i < Size || j < Size) {
        // Skip blank spaces in start
        while (start[i] =='_') {
            i++;
        }
        // Skip blank spaces in target
        while (target[j] =='_') {
            j++;
        }
        if (i == Size || j == Size) {
            break;
        }
        // Check for 'L' and 'R' conditions
        if (start[i] != target[j]) {
            return false;
        }
        if(start[i] == target[j]){
            if (start[i] =='L' && i < j) {
            return false;
        }
        if (start[i] =='R' && i > j) {
            return false;
        }
        }
        // Move to the next characters
        i++;
        j++;
    }

    // If we exit the loop without returning, it means we matched all characters
    return i==Size && j==Size;
    }
};