function search(arr) {
    if (!Array.isArray(arr) || !arr.length) {
        throw new Error("Not an array");
    }

    let left = 0,
        right = arr.length - 1,
        mid;

    while (left < right) {
        if (left + 1 === right) return arr[right];

        mid = Math.floor((left + right) / 2);

        if (arr[left] === arr[mid] && arr[right] === arr[mid]) {
            searchMin(arr, left, right);
        }
        
        if (arr[mid] < arr[left]) {
            right = mid;
        } else if (arr[mid] > arr[right]) {
            left = mid;
        } else {
            return arr[left];
        }
    }
    return arr[left];
}

function searchMin(arr, left, right) {
    let min = arr[left];
    while (left <= right) {
        if (arr[left] < min) min = arr[left];
        left ++;
    }
    return min;
}

// ****test****
console.log(search([3,4,1,2]));