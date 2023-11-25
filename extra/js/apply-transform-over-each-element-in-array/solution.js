/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    arr.forEach((value, index) => {
        arr[index] = fn(value, index);
    })
    return arr;
};
