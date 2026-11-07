class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();

        if (sLen > tLen) return false;

        vector<int> leftEnd(sLen + 1, tLen + 1);
        leftEnd[0] = 0;

        int tPos = 0;

        for (int sPos = 0; sPos < sLen; sPos++) {
            while (tPos < tLen && t[tPos] != s[sPos]) {
                tPos++;
            }

            if (tPos == tLen) break;

            leftEnd[sPos + 1] = tPos + 1;
            tPos++;
        }

        if (leftEnd[sLen] <= tLen) return true;

        vector<int> rightStart(sLen + 1, -1);
        rightStart[sLen] = tLen;

        tPos = tLen - 1;

        for (int sPos = sLen - 1; sPos >= 0; sPos--) {
            while (tPos >= 0 && t[tPos] != s[sPos]) {
                tPos--;
            }

            if (tPos < 0) break;

            rightStart[sPos] = tPos;
            tPos--;
        }

        for (int replaceIndex = 0; replaceIndex < sLen; replaceIndex++) {
            if (leftEnd[replaceIndex] < rightStart[replaceIndex + 1]) {
                return true;
            }
        }

        return false;
    }
};
