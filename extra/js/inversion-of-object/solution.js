/**
 * @param {Object|Array} obj
 * @return {Object}
 */
var invertObject = function (obj) {
    const ans = {};
    for (const [key, value] of Object.entries(obj)) {
        if (value in ans) {
            if (!Array.isArray(ans[value])) {
                ans[value] = [ans[value]];
            }
            ans[value].push(key);
        } else {
            ans[value] = key;
        }
    }
    return ans;
};