int lineWidth = 5;
int lineHeight = -5;
int i;
int[] num = new int[100];
float sum = 0;
String[] str = new String[256];
float average, dispersion;
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
    sum += num[i];
  }
  
  println("sum:"+sum);
  average = sum / str.length;
  println("average:"+average);
  
  sum = 0;
  for (i = 0; i < str.length; i++){
     sum += pow(num[i] - average, 2);
  }
  dispersion = sum / str.length;
  println("dispersion:"+String.format("%.3f",dispersion));
  
  println("standard deviation:"+String.format("%.3f",sqrt(dispersion)));
  
  noLoop();
}