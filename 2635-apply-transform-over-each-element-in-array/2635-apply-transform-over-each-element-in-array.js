/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map1 = function(arr, fn) {
    return arr.map(fn);
};
var map = function(arr, fn) {
    for(let i=0;i<arr.length;++i)
        arr[i] = fn(arr[i],i)
    return arr
};