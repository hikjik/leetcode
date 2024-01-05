/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function (fn, t) {
    let nextCallTime = 0;
    let timeout = null;
    return function (...args) {
        const delay = Math.max(0, nextCallTime - Date.now());
        clearTimeout(timeout);
        timeout = setTimeout(() => {
            fn(...args);
            nextCallTime = Date.now() + t;
        }, delay);
    }
};
