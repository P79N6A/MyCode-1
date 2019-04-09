// 判断key和value是否全部是小写
function islower(arr)
{
    var a =/^[A-Z]+$/;
    if(a.test(arr))
    {
        return false;
    }
    else
    {
        return true;
    }
}
var r1 = _.every(obj, function (value, key) {
    return islower(key) ;
});
var r2 = _.some(obj, function (value, key) {
    return islower(value);
});
