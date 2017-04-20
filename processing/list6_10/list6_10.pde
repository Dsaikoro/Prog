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

void keyPressed(){
  if (key == 's'){
    img.save("./data/newImage.png");
  }
}
void blueReverse2(){
  float r, g, b;
  for (int y = 0; y<200; y++){
    for(int x = 0; x < 200; x++){
      color c = img.get(x, y);
      
      r = red(c);
      g = green(c);
      b = 255 - blue(c);
      
      color c2 = color(r, g, b);
      img.set(x, y, c2);
    }
  }
}