
//'插入DOM'最后习题
var listbox = document.getElementById('test-list');
list = listbox.children;
var arr=[];
for(var i=0;i<list.length;i++){
    arr[i]=list[i];
}
arr.sort(function(x,y){
    if(x.innertext>y.innertext)
    {
        return 1;
    }
    else if(x.innerText<y.innerTe时xt)
    {
        return -1;
    }
    else 
    {
        return 0;
    }
});
for(var i=0;i<arr.length;i++)
{
    listbox.append(arr[i]);
}
