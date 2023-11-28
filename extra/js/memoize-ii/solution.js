class TrieNode {
    constructor() {
        this.children = new Map();
        this.has_value = false;
        this.value = null;
    }
};

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    set(path, value) {
        let node = this.root;
        for (const key of path) {
            if (!node.children.has(key)) {
                node.children.set(key, new TrieNode());
            }
            node = node.children.get(key);
        }
        node.has_value = true;
        node.value = value;
    }

    get(path) {
        let node = this.root;
        for (const key of path) {
            if (!node.children.has(key)) {
                return new TrieNode();
            }
            node = node.children.get(key);
        }
        return node;
    }
};

/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let trie = new Trie();
    return function (...args) {
        const node = trie.get(args);
        if (node.has_value) {
            return node.value;
        }
        const value = fn(...args);
        trie.set(args, value);
        return value;
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
