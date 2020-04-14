function formatAmount(num) {
    // 合法判断
  let s = String(num)
  for (let i = 0; i < s.length; i ++ ) {
      if ((s[i] < '0' || s[i] > '9') && s[i] != 'e') return '-'
      if (s[i] === 'e' && i !== s.indexOf('e')) return '-'
      if (s.indexOf('e') === 0 || s.indexOf('e') === s.length-1) return '-'
  }

    // 字符串转化为数字
    if (typeof num === 'string') {
      if (num.indexOf('e') > 0) {
          let str = num
          let index = str.indexOf('e') + 1;
          num = +str.substr(0, index-1)
          let p = +str.substr(index)
          for (let i = 0; i < p; i ++ ) num *= 10
      } else {	
          num = +num
      }
  }

    // 标记是否为负数
    let flag = false
  if (num < 0) {
      flag = true
      num = -num
  }

    let arr = []
  // 整数部分
  let num2 = Math.floor(num)
  
  while (num2 != 0) {
      arr.push(num2 % 1000)
      num2 = Math.floor(num2 / 1000)
  }

    let ans = ''
  if (flag) ans += '-'
  
  // 处理整数部分
  for (let i = arr.length-1; i >= 0; i -- ) {
      if (i != arr.length-1) ans += ','
      ans += arr[i]
  }

    ans += '.'
  
  // 处理小数部分
    if (String(num).indexOf('.') === -1) {
      ans += '00'
  } else {
         // 小数部分
      let num3 = num - num2
      let str = String(num3).substr(2)
      if (str.length >= 2) {
          ans += str.substr(0, 2)
      } else {
          ans += str
          ans += '0'
      }
  }
    return ans
}

console.log(formatAmount(2888.789))