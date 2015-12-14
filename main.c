//課題　： 黒線の長さを判別する
//提出日： 2015/12/15
//提出者： 中野太輔

//SPEED10000で250ms進むと1cm進むと仮定して作成

#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SPEED 10000
#define ADD 2500
#define TIME 250
#define COLOR 500

void Run(short speed_l, short speed_r);
int Move(int sen_l, int sen_r);   //左右のセンサーを元に動く。返り値は黒の個数を返す。
int Record(int black, int n);     //過去5cmの黒の数を記録する。返り値は黒の合計数。

int main(void)
{
  const unsigned short MainCycle = 60;
  Init(MainCycle);

  int color_l,color_r,black_num;
  int count = 0;

  LED(1);
  while(!getSW());
  LED(0);

  for(;;count++){
    color_l = ADRead(0);
    color_r = ADRead(1);
    black_num = Move(color_l, color_r);
    
    if(Record(black_num, count) == 10){
      break;
    }
    
  }
  return 0;
}

void Run(short speed_l, short speed_r)
{
  Mtr_Run_lv(speed_l, -speed_r, 0, 0, 0, 0);
  Wait(TIME);
}

int Move(int sen_l, int sen_r)
{
  if(sen_l > COLOR && sen_r > COLOR){
    LED(3);
    Run(SPEED, SPEED);
    return 2;
  }
  else if(sen_r > COLOR){
    LED(1);
    Run(SPEED+ADD, SPEED-ADD);
    return 1;
  }
  else if(sen_l > COLOR){
    LED(2);
    Run(SPEED-ADD, SPEED+ADD);
    return 1;
  }
  else{
    LED(0);
    Run(SPEED,SPEED);
    return 0;
  }
}

int Record(int black, int n){
  static int rec[5] = {0};
  int i,sum;

  rec[n%5] = black;

  for(i = 0; i < 5; i++){
    sum += rec[i];
  }
  
  return sum;
}
