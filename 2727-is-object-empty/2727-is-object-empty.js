/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(obj && Object.keys(obj).length === 0){
        return true;
    }
    else{
        return false;
    }
    
};