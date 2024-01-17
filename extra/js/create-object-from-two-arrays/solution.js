/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function (keysArr, valuesArr) {
    obj = {};
    for (let i = 0; i < keysArr.length; ++i) {
        if (keysArr[i] in obj) {
            continue;
        }
        obj[keysArr[i]] = valuesArr[i];
    }
    return obj;
};