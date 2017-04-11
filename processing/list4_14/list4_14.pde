int lv = 128;

void setup()
{
  size(320, 240);
}

void draw()
{
  fill(lv);
  rect(110, 70, 100, 100);
}

void mouseMoved()
{
  int dx = pmouseX - mouseX;
  if (dx > 0){
    lv = lv-2;
    if (lv < 0){
      lv = 0;
    }
  }
  else {
    lv = lv+2;
    if (lv > 255){
      lv = 255;
    }
  }
}