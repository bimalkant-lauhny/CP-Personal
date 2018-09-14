class Solution {
    /* 
       @param input: an abstract file system
       @return: return the length of the longest absolute path to file
     */ 
    int lengthLongestPath(&input) {
        int maxlen = 0, level = 1, count = 0; 
        unordered_map <int, int> levelLength; 
        levelLenght[0] = 0;
        bool isFile = false;

        int i = 0;
        while (i < input.length()) {

            while(input[i] == '\t') {
                ++level;
                ++i;
            }

            while (i < input.length() and input[i] != '\n') {
                if (input[i] == '.') {
                    isFile = True;
                }
                ++count;
                ++i;
            }


            if (isFile) {
                maxlen = max(maxlen, levelLength[level-1] + count);
            } else {
                levelLength[level] = levelLength[level-1] + count + 1;
            }
            count = 0;
            level = 1;
            isFile = false;
            ++i;
        }

        return maxlen;
    }
}
