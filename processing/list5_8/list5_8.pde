float rx = 0.0;  //rotation angle of x axis
float ry = 0.0;  //rotation angle of y axis
float rz = 0.0;  //rotation angle of z axis
boolean flg = true;  //flag of prespective projection

void setup(){
  size(320, 240, P3D);  //3DMode
  noStroke();  //Don't draw borders
}

void draw(){
  //Refresh the screen
  background(31);
  
  lights();  //turn on
  
  translate(width/2, height/2, -50);
  //Rotate
  rotateX(rx);
  rotateY(ry);
  rotateZ(rz);
  scale(50);  //Expanding by 50 times
  
  makeCube();  //Draw cube
}

void makeCube(){
  beginShape(QUADS);
  //front
  vertex(-1, -1, 1);
  vertex(-1, 1, 1);
  vertex(1, 1, 1);
  vertex(1, -1, 1);
  
  //back
  vertex(-1, -1, -1);
  vertex(-1, 1, -1);
  vertex(1, 1, -1);
  vertex(1, -1, -1);
  
  //top
  vertex(-1, -1, 1);
  vertex(1, -1, 1);
  vertex(1, -1, -1);
  vertex(-1, -1, -1);
  
  //bottom
  vertex(-1, 1, 1);
  vertex(1, 1, 1);
  vertex(1, 1, -1);
  vertex(-1, 1, -1);
  
  //left
  vertex(-1, -1, 1);
  vertex(-1, 1, 1);
  vertex(-1, 1, -1);
  vertex(-1, -1, -1);
  
  //right
  vertex(1, -1, 1);
  vertex(1, 1, 1);
  vertex(1, 1, -1);
  vertex(1, -1, -1);
  endShape();
}

void keyPressed(){
  switch (keyCode){
    case UP:  rx -= 0.1;  break;
    case DOWN: rx += 0.1;  break;
    case LEFT: ry -= 0.1;  break;
    case RIGHT: ry += 0.1; break;
  }
}

void mouseDragged(){
  rz = mouseX * 0.01;
}