
//'删除DOM'最后习题
var listbox = document.getElementById('test-list');
var list = [];
for(var i=0;i<listbox.children.length;i++)
{
    list.push(listbox.children[i]);
}
var 
    j=0;
    i=0;
while(1){
    if(i==list.length)
    {
        break;
    }
    if(list.innerText=='JavaScript'||list.innerText=='HTML'||list.innerText=='CSS')
    {
        i++;
    }
    else {
        var parentnode = list[i].parentElement;
        parentnode.removeChild(list[i]);
    }
    
}