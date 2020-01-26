#include <TVout.h>

TVout TV;
unsigned char x,y;
unsigned int paso,largo,gordo;

void setup()  {
  x=128;
  y=96;
  paso=2 ;
  largo=15;
  gordo=3;
  TV.start_render(_NTSC);	//for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
}

void loop() {
  TV.clear_screen();
  for(int j=0; j+gordo<y;j=j+gordo){
    for(int i=0; i<x;i=i+paso){
      //x,y,alto,ancho,colorlinea,color relleno,radius=0,safe=1
      TV.draw_box(i-paso,j,largo,gordo+1,0,0,0,0);
      TV.draw_box(i,j,largo,gordo,1,1,int(gordo/2),0);
      TV.delay_frame(1);
    }
  }
  TV.delay_frame(60);
}
