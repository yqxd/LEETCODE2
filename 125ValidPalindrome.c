bool isPalindrome(char* s) {
    int head = 0, tail = strlen(s) - 1;
    while (head < tail) {
        if ((s[head] >= 'A' && s[head] <= 'Z') ||
            (s[head] >= 'a' && s[head] <= 'z') ||
            (s[head] >= '0' && s[head] <= '9')) {
            if ((s[tail] >= 'A' && s[tail] <= 'Z') ||
                (s[tail] >= 'a' && s[tail] <= 'z' ||
                 (s[tail] >= '0' && s[tail] <= '9'))) {
                if (s[head] == s[tail] || s[head] - s[tail] == 'a' - 'A' ||
                    s[head] - s[tail] == 'A' - 'a') {
                    if ((s[head] != s[tail]) &&
                        ((s[tail] >= '0' && s[tail] <= '9') ||
                         (s[head] >= '0' && s[head] <= '9'))) {
                        return false;
                    }
                    head++;
                    tail--;
                } else {
                    return false;
                }
            } else {
                tail--;
            }
        } else {
            head++;
        }
    }
    return true;
}