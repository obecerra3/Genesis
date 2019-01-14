#include <Magick++.h> 
#include <iostream>
#include <cmath>
using namespace std; 
using namespace Magick; 

#define CANVAS_WIDTH 500
#define CANVAS_HEIGHT 500



int main(int argc,char **argv) 
{ 
  InitializeMagick(*argv);
  try {
    Geometry g1(CANVAS_WIDTH, CANVAS_HEIGHT);
    ColorRGB white(1.0, 1.0, 1.0);
    ColorRGB black(0.0, 0.0, 0.0);
    Image image(g1, white);
    
    
    // look into pixel cache
    for (int i = 0; i < CANVAS_WIDTH; i++) {
        for (int j = 0; j < CANVAS_HEIGHT; j++) {
        ColorRGB color(0.0,(double)i/(double)CANVAS_WIDTH,(double)j/(double)CANVAS_HEIGHT);
            image.pixelColor(i,j,color);
        }
    }
    
    
     
    image.write( "image.png" ); 
  } catch( Exception &error_ ) 
    { 
      cout << "Caught exception: " << error_.what() << endl; 
      return 1; 
    } 
  return 0; 
}
