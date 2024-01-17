/**
 * @return {Object}
 */
var createInfiniteObject = function () {
    return new Proxy({}, {
        get: function (target, propKey) {
            return function () {
                return String(propKey);
            };
        }
    });
};

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */