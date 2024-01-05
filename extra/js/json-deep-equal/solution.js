/**
 * @param {null|boolean|number|string|Array|Object} o1
 * @param {null|boolean|number|string|Array|Object} o2
 * @return {boolean}
 */
function replacer(key, value) {
    if (value && typeof value === "object" && !Array.isArray(value)) {
        return Object.fromEntries(Object.entries(value).sort());
    }
    return value;
};

var areDeeplyEqual = function (o1, o2) {
    return JSON.stringify(o1, replacer) === JSON.stringify(o2, replacer);
};
