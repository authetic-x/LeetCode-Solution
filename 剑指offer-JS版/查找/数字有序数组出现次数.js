/*
    用二分先找到位置，再确定边界
*/

function solution(arr, key) {
    let left = 0,
        right = arr.length-1,
        mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid;
        } else if (arr[mid] < key) {
            left = mid;
        } else {
            break;
        }
    }
    let res = 1,
        i = mid-1,
        j = mid+1;
    while (i >= 0) {
        if (arr[i--] === key) res++;
    }
    while (j < arr.length) {
        if (arr[j++] === key) res++;
    }

    return res;
}

const nums = [1, 2, 3, 3, 3, 4, 5];
console.log(solution(nums, 3));