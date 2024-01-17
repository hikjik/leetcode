/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function (target) {
    let l = 0, r = this.length - 1;
    while (l <= r) {
        const m = (l + r) >> 1;
        if (this[m] <= target) {
            l = m + 1;
        } else if (this[m] > target) {
            r = m - 1;
        }
    }
    return l && this[l - 1] == target ? l - 1 : -1;
};


// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5