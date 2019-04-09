  //canvas 作业

  var
  canvas = document.getElementById('stock-canvas'),
  width = canvas.width,
  height = canvas.height,
ctx = canvas.getContext('2d');
console.log(JSON.stringify(data[0])); 
// {"date":"20150602","open":4844.7,"close":4910.53,"high":4911.57,"low":4797.55,"vol":62374809900,"change":1.69}
ctx.clearRect(0, 0, width, height);
ctx.fillText('Test Canvas', 10, 10);

//画坐标轴
var path = new Path2D();
path.moveTo(0,height);
path.lineTo(0,0);
path.moveTo(0,height);
path.lineTo(width,height);
ctx.stroke(path);

var line_x=10;//每日的起始坐标
var next=10;//每日的间隔
var rectwidth=6;

data.forEach(function(element) {
  //画高低线
  line_x+=next;

  var line_high = (element.high-element.low)/2000*height;//假设整个图的高度为800点
  var line_y = (1-(element.high-3000)/2000)*height;
  path.moveTo(line_x,line_y);
  path.lineTo(line_x,line_y+line_high);
  ctx.stroke(path);

  //画增减柱状图
  var exchange = element.open-element.close;
  var dayh = (element.open-element.close)/2000*height;
  if(exchange>=0) 
  {
      ctx.fillStyle='green';
      ctx.fillRect(line_x-rectwidth/2,(1-(element.open-3000)/2000)*height,rectwidth,dayh);
  }
  else 
  {
      ctx.fillStyle = 'red';
      ctx.fillRect(line_x-rectwidth/2,(1-(element.close-3000)/2000)*height,rectwidth,dayh);
  }
});