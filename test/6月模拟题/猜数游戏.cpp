#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 猜数字一道比较新颖的题，从题目类型来看，很像是
 *        递归的类型，我不确定递归能不能做，就算能运行时间
 *        也超时了。
 *        正确解法是将1到n的数字分为很多部分，每个部分由一个素数
 *        以及它们的幂次方组成，例如当n为64时，可分为：
 *        2, 4, 8, 16, 32, 64
 *        3, 9, 27
 *        5, 25
 *        7, 49
 *        ...
 *        这样分的目的是为了避免重复，第一次可能会觉得这方法是错的，
 *        好像是我们每次只检查素数，又只计入冥次方会漏掉一些数。
 *        其实没有，以上述列表为例，当64为Y，它前面的数一定都为Y，
 *        当它为N，我们跳到32，当32为Y时，他前面的数也同样都为Y，
 *        于是32到64之间能被32之前的数整除的就也只能为Y了，比如34，40...
 *        这些数被很自然的处理掉了，每个部分可能构成的序列数为cnt+1，
 *        所以ans = ans*(cnt+1)
 */

const int maxn = 1e6+5;
const int mod = 1e9+7;
bool visited[maxn];

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (visited[i]) continue;
        for (int j = i; j <= n; j+i) visited[j] = 1;
        int tmp = n, cnt = 0;
        while (tmp >= i) {
            tmp /= i;
            cnt++;
        }
        ans = ans * (cnt+1) % mod;
    }
    cout << ans << endl;
    return 0;
}