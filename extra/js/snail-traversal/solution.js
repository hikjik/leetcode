/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function (rowsCount, colsCount) {
    if (this.length != rowsCount * colsCount) {
        return [];
    }

    let arr = [];
    for (let i = 0; i < rowsCount; ++i) {
        arr[i] = [];
    }

    let k = 0;
    for (let j = 0; j < colsCount; ++j) {
        if (j & 1) {
            for (let i = rowsCount - 1; i >= 0; --i) {
                arr[i][j] = this[k++];
            }
        } else {
            for (let i = 0; i < rowsCount; ++i) {
                arr[i][j] = this[k++];
            }
        }
    }
    return arr;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */