PImage img;  //picture data
void settings(){
  img = loadImage("dog.jpg");
  size(img.width, img.height);
}


void draw(){
  //display picture
  image(img, 0, 0);
  println(img.width);
  println(img.height);
}