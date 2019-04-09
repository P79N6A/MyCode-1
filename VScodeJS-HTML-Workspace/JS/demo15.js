//事件练习
function setall(select)
{
    selectAll.prop('checked',select)
    if(select)
    {
        selectAllLabel.hide();
        deselectAllLabel.show();
    }
    else{
        selectAllLabel.show();
        deselectAllLabel.hide();
    }
};

selectAll.change(function(e)
{
    setall($(this).is(':checked'));
    langs.prop('checked',$(this).is(':checked'));
});

function isall()
{
    setall((langs.filter(':checked')).length == langs.length);
}

invertSelect.click(function(e)
{
    langs.each(function()//此处不能使用箭头函数，因为箭头函数
    {
        if($(this).is(':checked'))
        {
            $(this).prop('checked',false);
        }
        else 
        {
            $(this).prop('checked',true);
        }
    });
    isall();
});

langs.change(function(e)
{
    isall();
    //console.log((langs.filter(':checked')).length);
});