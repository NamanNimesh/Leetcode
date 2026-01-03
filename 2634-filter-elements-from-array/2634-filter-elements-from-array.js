/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ansArr = [];
    for(let i =0; i< arr.length;i++){
        if(fn(arr[i],i)){
            ansArr.push(arr[i]);
        }
    }
    
    return ansArr;
};