PImage img;  //picture data

void settings(){
  img = loadImage("dog.jpg");
  size(img.width, img.height);
}


void draw(){
  //display picture
  image(img, 0, 0);
}

void mousePressed(){
  img.loadPixels();
  blueReverse();
}

void blueReverse(){
  int n = img.width*img.height;
  float r, g, b;
  for (int i = 0; i<n; i++){
    r = red(img.pixels[i]);
    g = green(img.pixels[i]);
    b = 255 - blue(img.pixels[i]);
    
    img.pixels[i] = color(r, g, b);
  }
  img.updatePixels();
}