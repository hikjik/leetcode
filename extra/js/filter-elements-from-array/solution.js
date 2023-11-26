/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    let ans = [];
    arr.forEach((value, index) => {
        if (fn(value, index)) {
            ans.push(value);
        }
    });
    return ans;
};
