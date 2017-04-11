int lineWidth = 5;
int lineHeight = -5;
int i;

void setup(){
  size(500,500);
  frameRate(20);
}

void draw(){
  background(128);
  translate(0,height);
  
  for (i = 0; i < 100; i++){
    rect(lineWidth*i, 0, lineWidth, lineHeight*(i+1));
    println(i+1);
  }
  noLoop();
}