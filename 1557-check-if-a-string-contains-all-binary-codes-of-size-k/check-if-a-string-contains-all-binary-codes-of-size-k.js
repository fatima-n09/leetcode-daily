/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var hasAllCodes = function(s, k) {
    const set = new Set();
    if(s.length < k) return false;
    for(let i =0; i<=s.length-k; i++){
        set.add(s.substring(i, i+k));
    }
    return set.size === (1<<k);
};
