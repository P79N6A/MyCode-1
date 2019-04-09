'use strict';
function pow(x,y)
{
    return x*y;
}
function string2int(s) {
    var arr=[];
    for(var a in s)
    {
    arr[a]=s[a]-'0';
    }
    var b=arr.reduce(function(x,y)
    {
    return x*10+y;
    }
    );
    return b;
}    
function normalize()
{
    for(var a in arr)
    {
        arr[a]=arr[a][0].toUpperCase()+arr[a].substring(1).toLocaleLowerCase();
        console.log(arr[a]);
    }
}
var arr = ['adam', 'LISA', 'barT'];
var results =string2int(arr); // [1, 4, 9, 16, 25, 36, 49, 64, 81]

// 测试:
if (normalize(['adam', 'LISA', 'barT'])=== ['Adam', 'Lisa', 'Bart']) {
    console.log('测试通过!');
}
else {
    console.log('测试失败!');
}