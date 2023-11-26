/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (!obj) {
        return false;
    }
    if (typeof obj !== 'object') {
        return obj;
    }

    if (Array.isArray(obj)) {
        const arr = [];
        obj.forEach((x) => {
            const res = compactObject(x);
            if (res) {
                arr.push(res);
            }
        });
        return arr;
    }

    let newObj = {};
    for (const key in obj) {
        const res = compactObject(obj[key])
        if (res) {
            newObj[key] = res;
        }
    }
    return newObj;
};
