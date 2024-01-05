/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Promise<any>}
 */
var promisePool = async function (functions, n) {
    let i = 0;
    async function next() {
        const fn = functions[i++];
        if (fn) {
            await fn();
            return next();
        }
    }
    return Promise.all(Array(n).fill().map(next));
};
