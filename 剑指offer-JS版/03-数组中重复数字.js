/*
    Q：n个数字，范围为0~n-1，判断有没有重复的数字
    Tips: 将下标为i的数放到下标为numbers[i]的位置
*/

function duplicate(numbers) {
    for (let i = 0; i < numbers.length; i ++ ) {
        while (i != numbers[i]) {
            if (numbers[i] == numbers[numbers[i]]) {
                return true
            }
            numbers[i], numbers[numbers[i]] = numbers[numbers[i]], numbers[i]
        }
    }
    return false
}

console.log(duplicate([0, 1, 1]))