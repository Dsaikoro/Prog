int lineWidth = 5;
int lineHeight = -5;
int i;
int[] num = new int[100];
int sum = 0;
String[] str = new String[100];

void setup(){
  size(500,500);
  frameRate(20);
}

void draw(){
  background(128);
  translate(0,height);
  
  for (i = 0; i < 100; i++){
    num[i] = (int)random(1, 100);
    rect(lineWidth*i, 0, lineWidth, lineHeight*num[i]);
    println(num[i]);
    saveStrings("hoge.txt", nf(num, 1));
  }
  noLoop();
}