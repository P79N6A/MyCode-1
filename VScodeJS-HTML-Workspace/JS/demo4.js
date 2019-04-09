function Student(props){
    this.name = props.name || '匿名';
    this.grade = props.grade || 1;
}

Student.prototype.hello = function(){
    console.log("hello, "+this.name+'!');
}

function createStudent(props){
    return new Student(props ||{});//“||”表示默认值
}

var xiaoming = createStudent({
    name : '小明'
});

console.log(xiaoming.grade);