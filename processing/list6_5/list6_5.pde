int cnt = 0;
void setup(){
  size(320, 240);
  smooth();
}

void draw(){
  if (cnt < 50){
    float r = random(0, 255);
    float g = random(0, 255);
    float b = random(0, 255);
    stroke(r, g, b);
    fill(r, g, b);
    
    float x = random(0, width);
    float y = random(0, height);
    float d = random(10, 30);
    ellipse(x, y, d, d);
    
    saveFrame("./data/dot-####.png");
    
    cnt++;
  }
  else{
    noLoop();
  }
}