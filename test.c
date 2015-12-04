#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <time.h>

#define DEV_NAME "/dev/ttyUSB0"
#define _POSIX_SOURCE 1
#define BAUDRATE B115200
#define BUFFSIZE 256
#define STOP 0
#define CW 1
#define CCW 2
#define SET 3
 
void SerialInit(int fd);
int Move(unsigned id, int fd, int mode, int setpos);
void ReadID(int fd);
void WriteID(unsigned char id, int fd);
void ReadParam(unsigned char id, unsigned char sc, int fd);
void WriteParam(unsigned char id, unsigned char sc, int fd);
void Write(int fd, unsigned char *tx, unsigned char *rx, unsigned tx_data, unsigned rx_data);
void ReSet(int fd);

int main(){
  int fd;
  int pos, r_pos;
  int i, id;
  struct termios oldtio, newtio;

  fd = open(DEV_NAME,O_RDWR);         // デバイスファイル（シリアルポート）オープン
  if(fd<0){                                   // デバイスの open() に失敗したら
    perror(DEV_NAME);
    exit(1);
  }
  tcgetattr(fd, &oldtio);
  // 
  SerialInit(fd);
  
  
  //for(id = 2; id < 3; id++){     
  id = 1; 
  /*for(i = 0; i < 3; i++){
    pos = Move(id, fd, STOP) + 500;
    printf("tx_pos=%d\n", pos);    
    r_pos = SetPos(id, pos, fd);
    printf ("rx_pos = %d\n",  r_pos);
    sleep(1);
  }
  */
  
  
  Move(id,fd, CW,0);
  sleep(1);
  Move(id,fd, CCW,0);
  sleep(1);
  //Move(id, fd, SET, 5000);
  //sleep(1);
  
  Move(id, fd, STOP,0);
  
  //SetPos(id, 5000,fd);
  /*
  r_pos = Move(id, fd, STOP);
  sleep(1);
  Move(id, fd, CW);
  sleep(1);
  Move(id, fd, STOP);
  */
  //Move(id, fd, 3);
  //ReadID(fd);
  //WriteID(1,fd);
  //ReadID(fd);
  //ReadParam(2,0,fd);
  //WriteParam(1,4,fd);

  tcsetattr(fd, TCSANOW, &oldtio);
  close(fd);
  return 0;
}

void SerialInit(int fd){
  struct termios tio;
  tcgetattr(fd, &tio);
  tio.c_cflag = CS8 | CLOCAL | CREAD | PARENB;
  tio.c_cflag &= ~PARODD;
  /* 
     BAUDRATE: ボーレートの設定．cfsetispeed と cfsetospeed も使用できる． 
     CS8     : 8n1 (8 ビット，ノンパリティ，ストップビット 1) 
     CLOCAL  : ローカル接続，モデム制御なし 
     CREAD   : 受信文字(receiving characters)を有効にする． 
  */  
  
  tio.c_cc[VTIME] = 0; /* キャラクタ間タイマは未使用 */  
  
  /* 
     IGNPAR  : パリティエラーのデータは無視する      
  */ 
  tio.c_iflag = IGNPAR;  
  
  // ボーレートの設定  
  cfsetispeed(&tio, BAUDRATE);  
  cfsetospeed(&tio, BAUDRATE);  
  // デバイスに設定を行う  
  tcsetattr(fd, TCSANOW, &tio);
}

int SetPos(unsigned char id, int pos, int fd){
  unsigned char tx[3];
  unsigned char rx[6];
  int i,num,flag;
  int dat;

  
  tx[0] = 0x80 | id;
  tx[1] = (unsigned char)(pos >> 7 & 0x7F);
  tx[2] = (unsigned char)(pos & 0x7F);
  
  for(i = 0; i < 3; i++) printf("tx[%d] = %d\n", i, tx[i]);
  for(i = 0; i < 6; i++) rx[i] = i;
  //for(i = 0; i < 6; i++) printf("rx[%d] = %d\n", i, rx[i]);

  flag = 0;
  write(fd,tx,3);
  read(fd,rx,6);
  for(i = 0; i < 3; i++){
    if(tx[i] =! rx[i]){
      printf("tx[%d]=%d : rx[%d]=%d\n", i, tx[i], i, rx[i]);
      flag = 1;
    }
  }
  sleep(1);
  
  for(i = 0; i < 3; i++) printf("tx[%d] = %d\n", i, tx[i]);
  for(i = 0; i < 6; i++) printf("rx[%d] = %d\n", i, rx[i]);

  dat = (int)(rx[4] & 0x7F);
  dat = (dat << 7) + (int)rx[5];

  return dat;
}

int Move(unsigned id, int fd, int mode, int setpos){
  unsigned char tx[3];
  unsigned char rx[6];
  int i,pos,flag,dat;
  flag = 1;
  switch(mode){
  case STOP: pos = 0; break;
  case CW: pos = 8000; break;
  case CCW: pos = 7000; break;
  case SET: pos = setpos; break;
  default : exit(1);
  } 
  tx[0] = 0x80 | id;
  tx[1] = (unsigned char)((pos) >> 7 & 0x7F);
  tx[2] = (unsigned char)((pos) & 0x7F);
  
  while(flag){
    flag = 0;
    write(fd,tx,3);
    read(fd,rx,6);
    for(i = 0; i < 3; i++){
      if(tx[i] =! rx[i]){
	printf("tx[%d]=%d : rx[%d]=%d\n", i, tx[i], i, rx[i]);
	flag = 1;
      }
    }
    if(flag){
      sleep(1);
      ReSet(fd);
    }
  }
  
  dat = (int)(rx[4] & 0x7F);
  dat = (dat << 7) + (int)rx[5];

  for(i = 0; i < 3; i++) printf("tx[%d] = %d\n", i, tx[i]);
  for(i = 0; i < 6; i++) printf("rx[%d] = %d\n", i, rx[i]);
  printf ("now_pos = %d\n",  dat);

  return dat;
}

void ReadID(int fd){
  unsigned char id,i;
  unsigned char tx[4];
  unsigned char rx[5];
  int loop = 1;

  tx[0] = 0xFF;
  for(i = 1; i < 4; i++) tx[i] = 0x00;
  while(loop){
    rx[4] = 33;
    write(fd, tx, 4);
    sleep(1);
    read(fd, rx, 5);
    
    //for(i = 0; i < 5; i++) printf("rx[%d] = %x\n", i, rx[i]);
    id = rx[4] ^ 0xE0; 
    if(id < 0 || id > 32) printf("Failed to ID Reading\n");
    else{
      printf("Success Reading: ID is %d\n", id);
      loop = 0;
    }
  }
}

void WriteID(unsigned char id, int fd){
  unsigned char i,rid;
  unsigned char tx[4];
  unsigned char rx[5];
  int loop = 1;
  tx[0] = 0xE0 | id;
  for(i = 1; i < 4; i++) tx[i] = 0x01;
  
  while(loop){
    rx[4] = 33;
    write(fd, tx, 4);
    sleep(1);
    read(fd, rx, 5);
    
    //for(i = 0; i < 4; i++) printf("tx[%d] = %d\n", i, tx[i]);
    //for(i = 0; i < 5; i++) printf("rx[%d] = %d\n", i, rx[i]);
    id = rx[4] ^ 0xE0; 
    if(id < 0 || id > 32) printf("Failed to ID Writing\n");
    else {
      printf("Success Writing: ID is %d\n", id);
      loop = 0;
    }
  }
}

void ReadParam(unsigned char id, unsigned char sc, int fd){
  unsigned char tx[2];
  unsigned char rx[68];
  unsigned char tx_write[66];
  unsigned char rx_write[68];
  int i;

  if(sc < 0 || sc > 4) printf("Error SC");
  tx[0] =  0xA0 | id;
  tx[1] = sc;
  for(i = 0; i < 68; i++) rx[i]=i;

  write(fd, tx, 2);
  sleep(1);
  read(fd, rx, 68);
  printf("%x\n",id);
  //rx[6] = rx[6] << 4;
  for(i = 0; i < 4; i++) printf("rx[%d] = %x\n", i, rx[i]);
  for(i = 4; i < 68; i++) printf("EEPEOM[%d] = %x\n", i-3, rx[i]);
  sleep(1);
 
  /*  
  tx_write[0] = id | 0xC0;
  tx_write[1] = sc;
  for(i = 2; i < 66; i++) tx_write[i] = rx[i+2];
  tx_write[16] = 0;
  
  write(fd,tx_write,66);
  read(fd,rx_write,68);
  
  for(i = 0; i < 66; i++) printf("tx_write[%d] = %x\n", i, tx_write[i]);
  for(i = 0; i < 68; i++) printf("rx_write[%d] = %x\n", i, rx_write[i]);
  */
}

void WriteParam(unsigned char id, unsigned char sc, int fd){
  unsigned char tx[3];
  unsigned char rx[6];
  int i;

  tx[0] = 0xC0 | id;
  tx[1] = sc;
  tx[2] = 0x4B;

  write(fd, tx, 3);
  read(fd, rx, 6);

  for(i = 0; i < 6; i++) printf("rx[%d] = %x\n", i, rx[i]);
}


void Write(int fd, unsigned char *tx, unsigned char *rx, unsigned tx_data, unsigned rx_data){
  int i,flag;
  flag = 1;
  printf("Write Start\n");

  while(flag){
    flag = 0;
    write(fd,tx,tx_data);
    read(fd,rx,rx_data);
    printf("Read End\n");
    for(i = 0; i < tx_data; i++){
      if(tx[i] =! rx[i]){
	printf("Error\n");
	flag = 1;
      }
    }
    if(flag) ReSet(fd);
    sleep(1);
  }
  printf("Write END\n");
}


void ReSet(int fd){
  close(fd);

  fd = open(DEV_NAME,O_RDWR);         // デバイスファイル（シリアルポート）オープン
  if(fd<0){                                   // デバイスの open() に失敗したら
    perror(DEV_NAME);
    exit(1);
  }
  
  SerialInit(fd);
}

