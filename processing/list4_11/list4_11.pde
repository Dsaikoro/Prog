float x, y;
PImage img;
boolean bgImage = false;

void setup(){
  size(320, 240);
}

void draw(){
  if (mousePressed == true){
    if (bgImage == false)  background(204);
    else image(img, 0, 0);
    line(x, y, mouseX, mouseY);
  }
}

void mousePressed(){
  x = mouseX;
  y = mouseY;
}

void mouseReleased(){
  img = get(0, 0, width, height);
  bgImage = true;
}