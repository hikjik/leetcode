/**
 * @param {Array<Function>} functions
 * @param {number} ms
 * @return {Array<Function>}
 */
var delayAll = function (functions, ms) {
    return functions.map((func) => () => {
        return new Promise((resolve) => {
            setTimeout(() => resolve(func()), ms)
        });
    });
};
