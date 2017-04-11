int lineWidth = 5;
int lineHeight = -5;
int i,j,tmp;
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
  }
  
  for (i = 0; i < 100; i++){
    for(j = 99; j > 0+i; j--){
      if (num[j] < num[j-1]){
         tmp = num[j];
         num[j] = num[j-1];
         num[j-1] = tmp;
      }
    }
    rect(lineWidth*i, 0, lineWidth, lineHeight*num[i]);
    println(num[i]);
  }
  
  noLoop();
}