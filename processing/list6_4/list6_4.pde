void setup(){
  size(320, 240);
  noStroke();  //don't draw outline
  fill(0);
  smooth();
}

void draw(){
  if (mousePressed){
    ellipse(mouseX, mouseY, 20, 20);
  }
}

void keyPressed(){
  if (key == 's'){
    saveFrame("newImage.png");
  }
}