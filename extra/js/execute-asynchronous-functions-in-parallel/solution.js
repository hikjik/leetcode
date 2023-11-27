/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        let ans = new Array(functions.length);
        let cnt = 0;
        functions.forEach((fn, i) => {
            fn().then(res => {
                ans[i] = res;
                ++cnt;
                if (cnt === functions.length) {
                    resolve(ans);
                }
            }).catch(err => reject(err));
        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */