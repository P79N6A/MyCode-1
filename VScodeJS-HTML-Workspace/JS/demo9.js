var username = document.getElementById('username');
var password = document.getElementById('password');
var password2 = document.getElementById('password-2');
var a =new RegExp('\w{3-10}');
if(a.test(username)&&b.length>=6&&b.length<=20&&password===password-2)
{
    return true;
}
else
{
    return false;
}