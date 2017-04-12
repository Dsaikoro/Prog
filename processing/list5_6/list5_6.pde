float rx = 0.0;  //rotation angle of x axis
float ry = 0.0;  //rotation angle of y axis
float rz = 0.0;  //rotation angle of z axis

void setup(){
  size(300, 300, P3D);  //3DMode
  noStroke();  //Don't draw borders
}

void draw(){
  //Refresh the screen
  background(204);
  
  //Move the origin to the center of screen
  translate(width/2, height/2, 0);
  rotateX(rx);
  rotateY(ry);
  rotateZ(rz);
  scale(50);  //Expanding by 50 times
  
  
  makeCube();  //Draw cube
}

void makeCube(){
  beginShape(QUADS);
  //front
  fill(255, 0, 0);
  vertex(-1, -1, 1);
  vertex(-1, 1, 1);
  vertex(1, 1, 1);
  vertex(1, -1, 1);
  
  //back
  fill(0, 255, 0);
  vertex(-1, -1, -1);
  vertex(-1, 1, -1);
  vertex(1, 1, -1);
  vertex(1, -1, -1);
  
  //top
  fill(0, 0, 255);
  vertex(-1, -1, 1);
  vertex(1, -1, 1);
  vertex(1, -1, -1);
  vertex(-1, -1, -1);
  
  //bottom
  fill(255, 255, 0);
  vertex(-1, 1, 1);
  vertex(1, 1, 1);
  vertex(1, 1, -1);
  vertex(-1, 1, -1);
  
  //left
  fill(255, 0, 255);
  vertex(-1, -1, 1);
  vertex(-1, 1, 1);
  vertex(-1, 1, -1);
  vertex(-1, -1, -1);
  
  //right
  fill(0, 255, 255);
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