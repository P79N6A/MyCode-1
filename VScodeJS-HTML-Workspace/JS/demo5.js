//原型继承（类似于c++类的继承）
function Student(props){
    this.name = props.name|| 'Unnamed';
}
Student.prototype.hello=function(){
    console.log('hello, '+this.name+'!');
}

function PrimaryStudent(props){
    Student.call(this,props);
    this.grade = props.grade || 1;
}

function F(){

}

function inherits(child,parent){
    var F = function(){
    };
    child.prototype=new F();
    F.prototype=parent.prototype;
    Child.prototype.constructor=child.prototype;
}

F.prototype=Student.prototype;
PrimaryStudent.prototype=new F();
PrimaryStudent.prototype.constructor = PrimaryStudent;

PrimaryStudent.prototype.getGrade = function(){
    return this.grade;
}

var xiaoming = new PrimaryStudent({
    name:'小明',
    grade:2
});

//console.log(xiaoming.name);
//console.log(xiaoming.grade);
console.log(typeof F);
console.log(typeof xiaoming);
console.log(F.prototype===Student.prototype);
console.log(xiaoming.__proto__.__proto__===Student.prototype);
console.log(PrimaryStudent.prototype===xiaoming.__proto__);
//console.log(xiaoming instanceof PrimaryStudent);
//console.log(xiaoming instanceof Student);

