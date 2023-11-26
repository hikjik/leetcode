/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if (n == 0) {
        return arr;
    }

    let ans = [];
    arr.forEach((x) => {
        if (Array.isArray(x)) {
            ans.push(...flat(x, n - 1));
        } else {
            ans.push(x);
        }
    });
    return ans;
};
