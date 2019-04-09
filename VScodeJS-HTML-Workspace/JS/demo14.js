//修改dom结构练习
var box= $('#test-div ul');
var insert =['Pascal','Lua','Ruby'];
for(let i=0;i<insert.length;i++)
{
    box.append('<li><span>'+insert[i]+'</span></li>');
}
var ul= $('#test-div>ul');
li = box.find('li');
li.sort((x,y)=>{
    var a = $(x).text();
    var b = $(y).text();
    if(a>b)
    {
        return 1;
    }
    else if(a==b)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
});
ul.append(li);