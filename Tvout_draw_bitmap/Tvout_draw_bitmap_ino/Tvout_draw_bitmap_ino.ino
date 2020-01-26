#include <TVout.h>

TVout TV;
unsigned char x,y;

void setup()  {
  x=0;
  y=0;
  TV.start_render(_NTSC);	//for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
}

void loop() {
  TV.clear_screen();
  //TV.select_font(_3X5); // using font 3x5
  TV.select_font(_5X7); // using font 5x7
  //TV.select_font(_8X8); // using font 8x8
  TV.print_str(20,20,"Oscar Rocks!!");
  //colors:
  // 0: black 
  // 1: white
  // 2: inverse
  TV.set_pixel(int(TV.horz_res()/2),int(TV.vert_res()/2),2);
  TV.delay_frame(60);
}
