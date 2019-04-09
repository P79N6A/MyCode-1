//class 继承
class Student{
    constructor(name){
        this.name=name;
    }
    hello(){
        console.log("hello, "+this.name+"!");
    }
}

var xiaoming = new Student("小明");
xiaoming.hello();