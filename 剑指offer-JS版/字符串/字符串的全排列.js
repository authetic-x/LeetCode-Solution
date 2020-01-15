/*
    很奇怪：字符串的交换函数怎么写都不行，解构成数组就没问题了
*/

function permutation(str) {
    str = [...str];
    if (str.length <= 1) return [str];
    let res = [];
    for (let i = 0; i < str.length; i ++ ) {
        if (i >= 1 && str[0] === str[i]) continue;
        str = swap(str, 0, i);
        console.log(str);
        let tmp = permutation(str.slice(1));
        tmp.forEach((value) => {
            res.push(str[0].concat(value));
        });
        str = swap(str, 0, i);
    }
    return res;
}

function swap(str, i, j) {
    [str[i], str[j]] = [str[j], str[i]];
    return str;
} 

// console.log(permutation("abc"));

console.log(swap("ab", 0 , 1)); // output: ab  strange!!!