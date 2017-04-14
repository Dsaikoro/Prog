float rx = 0.0;  //rotation angle of x axis
float ry = 0.0;  //rotation angle of y axis
float rz = 0.0;  //rotation angle of z axis
boolean flg = true;  //flag of prespective projection

void setup(){
  size(300, 300, P3D);  //3DMode
  noStroke();  //Don't draw borders
}

void draw(){
  //Refresh the screen
  background(204);
  
  //Prespective projection
  if (flg){
    loat aspect = float(width) / float(height);
    perspective(radiams(60), aspect, 100, -100);
    translate(width/2, height/2, -50);
  }
  //Parallel projection
  else{
    ortho(0, width, 0, height, -100, 100);
    translate(width, height, -50);
  }
  
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
  if (key == 'p')  flg = true;
  else if (key == 'o') flg = false;
  
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