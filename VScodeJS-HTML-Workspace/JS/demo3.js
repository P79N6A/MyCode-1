//创建对象，面向对象编程
'use strict'
function Student(name){
    this.name=name;
    /*this.hello=function(){
        console.log("hello, "+this.name+"!");
    }*/
}

Student.prototype.hello = function(){
    console.log("hello, "+this.name+" !");
};

var xiaoming = new Student("小明");
//console.log(xiaoming.name);
xiaoming.hello();
var xiaohong = new Student("小红");
console.log(xiaoming.hello===xiaohong.hello);
