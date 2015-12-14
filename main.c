#include "LPC13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

#define SPEED 10000
#define ADD 2500
#define TIME 500
#define COLOR 500

void Run(short speed_r, short speed_l);
int Move(int sen_l, int sen_r);
void Record(int color, int n);

int main(void)
{
	const unsigned short MainCycle = 60;
	Init(MainCycle);

	int color_l,color_r,color_num;
	int count = 0;

	LED(1);
	while(!getSW());
	LED(0);
	while(1){
		color_l = ADRead(0);
		color_r = ADRead(1);
		color_num = Move(color_l, color_r);
		Record(color_num, count%5);
		count++;
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

void Record(int black, int n){
	static int rec[5] = {0};
	int i,sum;

	rec[n] = black;

	for(i = 0; i < 5; i++){
		sum +=	rec[i];
	}

	if(sum == 10){
		while(1){
			Run(0,0);
		}
	}
}
