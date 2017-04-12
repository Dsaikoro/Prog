float rx = 0.0;  //rotation angle of x axis
float ry = 0.0;  //rotation angle of y axis
float rz = 0.0;  //rotation angle of z axis

void setup(){
  size(300, 300, P3D);  //3DMode
  smooth();
}

void draw(){
  //Refresh the screen
  background(204);
  
  //Move the origin to the center of screen
  translate(width/2, height/2, 0);
  
  //rotate
  rotateX(rx);
  rotateY(ry);
  rotateZ(rz);
  
  //first geometry
  pushMatrix();  //save coordinate
  translate(-100, 0, 0);  //move the origin
  box(40, 120, 60);
  popMatrix();  //load coordinate
  
  //second geometry
  pushMatrix();
  translate(100, 0, 0);
  sphere(60);            //Radius is 100 pixel
  popMatrix();
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