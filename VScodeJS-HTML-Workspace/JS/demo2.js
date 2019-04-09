//函数封装对象的创建
'use strict'
var student=
{
    name:"Robot",
    height:1.2,
    run:function(){
        console.log(this.name+" is running ...");
    }
};
 var xiaoming = {
     name : "小明"
 };
//xiaoming.__proto__=student;
function createStudent(name){
    var s = Object.create(student);
    s.name=name;
    return s ;
}
var xiaoming = createStudent("小明");

console.log(xiaoming.__proto__===student);
console.log(xiaoming.run());