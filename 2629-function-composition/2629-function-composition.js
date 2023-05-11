/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
	return function(x) {
        let val=x
        for(let j=functions.length-1;j>=0;--j){
            val = functions[j](val)
        }
        return val
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */