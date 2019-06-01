
// 先遍历一遍字符串得出空格的个数，计算出替换后字符串的长度
// 设置两个指针分别放在原字符串末尾和新字符串末尾，依次向前替换
void ReplaceBlank(char *str, int length) {
    if (str == nullptr || length <= 0) return;
    int len = 0, numOfBlank = 0;
    int i = 0;
    while (str[i] != '\0') {
        len ++;
        if (str[i] == ' ') {
            numOfBlank++;
        }
    }
    int newLen = len + numOfBlank*2;
    if (newLen > length) return;
    int i = len, j = newLen;
    while (i >= 0 && j > i) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}