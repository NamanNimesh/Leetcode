/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {

   var ansArr = [];
   for(var i = 0; i< arr.length;i++){
        ansArr.push(fn(arr[i],i));
   }
   return ansArr;
   
    
};