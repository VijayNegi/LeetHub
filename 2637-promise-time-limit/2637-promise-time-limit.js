/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
// Approach 1: Call Function Inside New Promise
var timeLimit1 = function(fn, t) {
	return async function(...args) {
        return new Promise((resolve,reject) => {
            setTimeout( ()=> {
                reject("Time Limit Exceeded")
            },t)
            fn(...args).then(resolve).catch(reject)
        })
    }
};
// Approach 2: Handle Clearing Timeout
var timeLimit2 = function(fn, t) {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timeout));
    })
  }
};
// Approach 3: Promise Race
var timeLimit3 = function(fn, t) {
  return async function(...args) {
    const timeLimitPromise = new Promise((resolve, reject) => {
      setTimeout(() => reject("Time Limit Exceeded"), t)
    });
    const returnedPromise = fn(...args);
    return Promise.race([timeLimitPromise, returnedPromise]);
  }
};

// Approach 4: Async/Await + Clearing Timeout
var timeLimit = function(fn, t) {
  return async function(...args) {
    return new Promise(async (resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);

      try {
        const result = await fn(...args);
        resolve(result);
      } catch(err) {
        reject(err);
      }
      clearTimeout(timeout);
    });
  };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */