/*
    将 we are family 替换为 we%20are%20family
*/

// 正则实现
function replaceEmp1(str) {
    const re = / /g;
    return str.replace(re, "%20");
}

// 经典实现：前计算替换后总长度，在从后往前填充
function replaceEmp2(str) {
    let blankLen = 0, resLen;
    for (ch of str) {
        if (ch === ' ') blankLen++;
    }
    resLen = str.length + 2 * blankLen;
    let res = new Array(resLen);

    for (let i = resLen-1, j = str.length-1; j >= 0; j -- ) {
        if (str[j] === ' ') {
            res[i--] = '0';
            res[i--] = '2';
            res[i--] = '%';
        } else {
            res[i--] = str[j];
        }
    }
    
    return res.join("");
}

console.log(replaceEmp1("we are happy"));
console.log(replaceEmp2("we are happy"));