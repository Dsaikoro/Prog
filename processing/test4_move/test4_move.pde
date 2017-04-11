int lineWidth = 5;
int lineHeight = -5;
int i,j;
int[] num = new int[100];
int tmp;
int changenum = 100;

void setup()
{
  size(500,500);
  frameRate(100);
  for (i = 0; i < 100; i++) num[i] = (int)random(1,100);
}

void draw()
{
  background(128);
  translate(0,height);
  
  for (i = 0; i < 100; i++){
    fill(255);
    if(changenum >= i) fill(255, 160, 122);
    rect(lineWidth*i, 0, lineWidth, lineHeight*num[i]);
  }
  changenum = change();
  
  if(changenum == 0) finish();
  
}

int change()
{
  for (i = 0; i < 100; i++){
    for(j = 99; j > 0+i; j--){
      if (num[j] < num[j-1]){
         tmp = num[j];
         num[j] = num[j-1];
         num[j-1] = tmp;
         return j;
      }
    }
  }
  return 0;
}

void finish()
{
  for (i = 0; i < 100; i++){
    fill(255);
    rect(lineWidth*i, 0, lineWidth, lineHeight*num[i]);
  }
  noLoop();
}