 
/****************************************************************************
  Implements the Boolean function F = ab' + bc'd'
****************************************************************************/ 
 
#include <Sim.h>                       // Interface to the "sim" package
 
void simnet()                          // Function must be named "simnet"
{
  Signal a, b, c, d, F1, F2;                // Switch and output objects 
 
  Signal nota, notb, notc, notd;
  Signal and1, and2;                   // Intermediate objects 
 
  // Components and interconnections
 
  Switch ( SD("1a"), a, 'a' );         // Switch a controlled by 'a' key
  Switch ( SD("2a"), b, 'b' );         // Switch b controlled by 'b' key
  Switch ( SD("3a"), c, 'c' );         // Switch c controlled by 'c' key
  Switch ( SD("4a"), d, 'd' );         // Switch d controlled by 'd' key
 
  Not ( SD("2b"), b, notb );           // NOT gates
  Not ( SD("3b"), c, notc );
  Not ( SD("4b"), d, notd );
  Not ( SD("5b"), a, nota );
  
 
  // And ( SD("2c"), (a, notb), and1 );   // AND gates                                      
  // And ( SD("3c"), (b, notc, notd), and2 );
  And ( SD("4c"), (nota, notb), and1);
  
 
  Or ( SD("2d"), (a, notb), F1 );    // OR gate
  Or ( SD("3d"), (a, and1), F2 );
  
 
  Probe ( (SD("2e"), "F1"), F1 );        // Probe
  Probe ( (SD("3e"), "F2"), F2 );
  
}

