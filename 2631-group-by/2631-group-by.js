/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let arr = {}
    for(const ele of this){
        const k = fn(ele)
        if(!arr[k])
            arr[k] = []
        arr[k].push(ele)
    }
    return arr
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */