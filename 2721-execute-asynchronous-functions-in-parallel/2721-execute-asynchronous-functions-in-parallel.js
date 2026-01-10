/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        const result = [];
        let counter = 0;
        let hasRejected = false;

        if (functions.length === 0) {
            resolve([]);
            return;
        }

        for (let i = 0; i < functions.length; i++) {
            functions[i]()
                .then(value => {
                    if (hasRejected) return;

                    result[i] = value;
                    counter++;

                    if (counter === functions.length) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    if (hasRejected) return;
                    hasRejected = true;
                    reject(error);
                });
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */