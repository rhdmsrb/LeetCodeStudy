class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        while (read < chars.size()) {
            int start = read;
            char currentChar = chars[read];
            while (read < chars.size() && chars[read] == currentChar) {
                read++;
            }
            int count = read - start;
            chars[write++] = currentChar;
            if (count > 1) {
                int digitStart = write;
                while (count > 0) {
                    chars[write++] = '0' + count % 10;
                    count /= 10;
                }
                reverse(chars.begin() + digitStart, chars.begin() + write);
            }
        }
        return write;
    }
};
