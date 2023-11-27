class EventEmitter {
    constructor() {
        this.map = new Map();
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.map.has(eventName)) {
            this.map.set(eventName, []);
        }

        const callbacks = this.map.get(eventName);
        callbacks.push(callback)

        return {
            unsubscribe: () => {
                const index = callbacks.indexOf(callback);
                if (index != -1) {
                    callbacks.splice(index, 1);
                }
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this.map.has(eventName)) {
            return [];
        }
        let ans = [];
        this.map.get(eventName).forEach((callback) => {
            ans.push(callback(...args));
        });
        return ans;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */