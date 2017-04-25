import processing.video.*;

Capture capImg;
String name = "BUFFALO BSWHD06M USB Camera";

void setup(){
  size(320, 240);
  //String[] cameras = Capture.list();
  //capImg = new Capture(this, cameras[0]);
  capImg = new Capture(this, width, height);
  capImg.start();
}

void captureEvent(Capture capImg){
  capImg.read();
}

void draw(){
  image(capImg, 0, 0);
  
}