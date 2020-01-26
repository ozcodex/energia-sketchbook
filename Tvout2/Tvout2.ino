#include <TVout.h>

TVout TV;
unsigned char x,y;
int AX = A1;
int AY = A2;
int SW = 4;
int LED = 13;

int deadZone = 10;
int calibrationX = -0;
int calibrationY= -0;

void setup()  {
  pinMode( SW, INPUT_PULLUP );
  x=0;
  y=0;
  deadZone = deadZone*1024/100;
  TV.start_render(_NTSC);	//for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
}

void loop() {
  //TV.clear_screen();
  TV.select_font(_8X8); // using font 8x8
  //max long str = 16 chars
  TV.print_str(0,0,"Prueba de TV!");
  TV.select_font(_5X7); // using font 5x7
  TV.print_str(20,20,"Oscar es genial!!");
  TV.select_font(_3X5); // using font 3x5
  TV.print_str(0,84,"abcdefghijklmnopqrstuvwxyz");
  TV.print_str(0,90,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  //escritura de parametros
  int x=analogRead(AX)+calibrationX;
  int y=analogRead(AY)+calibrationY;
  int s=!digitalRead(SW);
  
  //se dibuja el centro
  int cx=int(TV.horz_res()/2);
  int cy=int(TV.vert_res()/2);
  int r = 6;
  TV.draw_box(cx-(r*2),cy-(r*2),r*4,r*4,0,0,0,1);
  //calculo de deltas
  int dx= r-int(x*r*2/1024);
  int dy= r-int(y*r*2/1024);
  //se dibja el circulo
  if ( s )
    TV.draw_circle(cx-dy,cy+dx,4,1,1,1);
  else
    TV.draw_circle(cx-dy,cy+dx,4,1,0,1);
  //se pone el centro
  TV.set_pixel(cx,cy,2);
  
  //se pinta el texto
  TV.draw_box(0,70,128,7,0,0,0,1);
  TV.select_font(_5X7);
  if (x > (512 + deadZone)) TV.print_str(10,70,"arriba");
  if (x < (512 - deadZone)) TV.print_str(10,70,"abajo");
  if (y > (512 + deadZone)) TV.print_str(10,70,"derecha");
  if (y < (512 - deadZone)) TV.print_str(10,70,"izquierda");
  if (s) TV.print_str(10,70,"adentro");  
  
  TV.delay_frame(13);
}
