/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
    let ans = {};
    this.forEach((x) => {
        const res = fn(x);
        if (!(res in ans)) {
            ans[res] = [];
        }
        ans[res].push(x);
    });
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */