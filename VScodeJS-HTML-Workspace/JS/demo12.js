//查找和过滤
var obj={};
$('#test-form :input').filter(function()
{
    if((this.type == 'radio'&&!this.checked)||this.type=='submit')
    {
        return false;
    }
    return true;
}).map(function()
{
    obj[this.name]=this.value;
});
json = JSON.stringify(obj);