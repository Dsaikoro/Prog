int lineWidth = 5;
int lineHeight = -5;
int i;
int num;

void setup(){
  size(500,500);
  frameRate(20);
}

void draw(){
  background(128);
  translate(0,height);
  
  for (i = 0; i < 100; i++){
    num = (int)random(1, 100);
    rect(lineWidth*i, 0, lineWidth, lineHeight*num);
    println(num);
  }
  noLoop();
}