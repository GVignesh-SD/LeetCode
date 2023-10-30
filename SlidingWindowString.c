
#include <stdio.h>
#include <string.h>

int main() {
    int count[256] = {0};
    int l = 0;
    int r = 0;
    int answer = 0;
    int maxAnswer = 0;
    char *s = "pwwkew";

    while (r < strlen(s)) {
        if (count[s[r]] == 0) {
            count[s[r]]++;
            r++;
            answer = r - l;
            if (answer > maxAnswer) {
                maxAnswer = answer;
            }
        } else {
            count[s[l]]--;
            l++;
        }
    }

    printf("%d\n", maxAnswer);

    return 0;
}
