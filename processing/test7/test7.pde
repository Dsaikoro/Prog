int lineWidth = 5;
int lineHeight = -5;
int i;
int[] num = new int[100];
int sum = 0;
String[] str = new String[256];

void setup(){
  size(500,500);
  frameRate(20);
}

void draw(){
  background(128);
  translate(0,height);
  
  str = loadStrings("hoge.txt");
  println(str.length);
  for (i = 0; i != str.length; i++){
    num[i] = int(str[i]);
    println(num[i]);
    rect(lineWidth*i, 0, lineWidth, lineHeight*num[i]);
  }
  noLoop();
}