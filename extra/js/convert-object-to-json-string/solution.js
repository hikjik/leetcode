/**
 * @param {null|boolean|number|string|Array|Object} object
 * @return {string}
 */
var jsonStringify = function (object) {
    if (object === null) {
        return 'null';
    }
    if (Array.isArray(object)) {
        return `[${object.map(jsonStringify).join(',')}]`;
    }
    if (typeof object === 'object') {
        const pairs = Object.entries(object).map(([k, v]) => `"${k}":${jsonStringify(v)}`);
        return `{${pairs.join(',')}}`;
    }
    if (typeof object === 'string') {
        return `"${object}"`;
    }
    return String(object);
};
