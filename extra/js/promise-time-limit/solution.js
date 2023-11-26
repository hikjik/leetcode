/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {
    return async function (...args) {
        return new Promise((resolve, reject) => {
            const timeoutID = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            fn(...args)
                .then(result => resolve(result))
                .catch(error => reject(error))
                .finally(() => clearTimeout());
        });
    }
};
/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */