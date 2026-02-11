#version 3.5;

#include "colors.inc"

global_settings {
  assumed_gamma 1.0
}

camera {
  location  <9, 3, 3>
  direction 1.5*z                               
  look_at   <0.0, 0.0,  0.0>
}

sky_sphere {
  pigment {
    gradient y
    color_map {
      [0.0 rgb <0.6,0.7,1.0>]
      [0.7 rgb <0.0,0.1,0.8>]
    }
  }
}

light_source {
  <0, 0, 0>            // light's position (translated below)
  color rgb <1, 1, 1>  // light's color
  translate <30, 30, 30>
}

// ----------------------------------------

plane {
  y, -1
  pigment { color rgb <0.7,0.5,0.3> }
}
           

sphere {
  <0, 0.5, 0>, 1
  texture {
    pigment {
      color rgb <0.5,0.5,0.25>
    }
    finish{
      specular 0.1
    }
  }
}           
// Eyes        
sphere {
  <2.25, 0.35, -0.35>, 0.25
  texture {
    pigment {
      color rgb <0,0,0>
    }
    finish{
      specular 0.6   
    }
  }  
  scale <0.45,1.75,0.75>
}                    
sphere {
  <2.25, 0.35, 0.45>, 0.25
  texture {
    pigment {
      color rgb <0,0,0>
    }
    finish{
      specular 0.6   
    }
  }  
  scale <0.45,1.75,0.75>
}         

// Foots
                       
// CSG difference, subtract intersections of shapes 2...N from Shape1
difference {
   sphere {
          <0, 0, 0>, 0.25
          texture {
            pigment {           
              color rgb <0.4,0.3,0.15>
            }
            finish{
              specular 0.1
            }
          }               
          scale <2,1,1>
        }  
       box{
       <-0.5, 0.05, -0.5>                 
       <2,-1,1>                      
          scale <1,1,1> 
          texture {
            pigment {           
              color rgb <0.4,0.3,0.15>
            }
            finish{
              specular 0.1
            }
          }  
   }  
   translate <0,0,3> 
    
}
            
           