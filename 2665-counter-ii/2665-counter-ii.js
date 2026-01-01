/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currentCounter = init;

    return  {
        increment: ()=>{
            return ++currentCounter;
        },
        decrement: ()=>{
            return  --currentCounter;
        },
        reset: ()=>{
            return currentCounter = init;
            
        }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */