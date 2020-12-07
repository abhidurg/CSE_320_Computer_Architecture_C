
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;
  
  

  // Replace with code for your Pulsers
   Pulser ((SD("3a"), "i - Init"), Init, 'i', 1000);
   Pulser ((SD("4a"), "c - Clk" ), Clock,  'c', 1000);
  //Switch ((SD("1a"), "i - Init"  ), Init,   'i');
  //Switch ((SD("3a"), "c - Clock"), Clock,   'c');

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes

  Probe ( (SD("1c"), "w"), w);
  Probe ( (SD("2c"), "x"), x);
  Probe ( (SD("3c"), "y"), y);
  Probe ( (SD("4c"), "z"), z);
  
  






  
}



/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9;
  Signal W, X, Y, Z;
  

  // Replace with code for your DFFs


   Dff ((SD("1b"), "W"), (Init, W, Clock, Zero), w);
   Dff ((SD("2b"), "X"), (Zero, X, Clock, Init), x);
   Dff ((SD("3b"), "Y"), (Init, Y, Clock, Zero), y);
   Dff ((SD("4b"), "Z"), (Zero, Z, Clock, Init), z);

  // Dff ((SD("1b"), "W"), (Init, W, Clock, One), w);
  // Dff ((SD("2b"), "X"), (Init, X, Clock, Zero), x);
  // Dff ((SD("3b"), "Y"), (Init, Y, Clock, One), y);
  // Dff ((SD("4b"), "Z"), (Init, Z, Clock, Zero), z);

  // Dff ((SD("1b"), "W"), (Init, One, Clock, W), w);
  // Dff ((SD("2b"), "X"), (Init, Zero, Clock, X), x);
  // Dff ((SD("3b"), "Y"), (Init, One, Clock, Y), y);
  // Dff ((SD("4b"), "Z"), (Init, Zero, Clock, Z), z);
  
  

  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"3a"), x, notx );
  Not ( SD(sd,"5a"), y, noty );
  Not ( SD(sd,"7a"), z, notz );

  And ( SD(sd, "1d"), (noty, z), and1);
  And ( SD(sd, "2d"), (notx, z), and2);
  And ( SD(sd, "3d"), (noty, notz), and3);
  And ( SD(sd, "4d"), (w, y), and4);
  And ( SD(sd, "5d"), (notw, noty), and5);
  And ( SD(sd, "6d"), (x, z), and6);
  And ( SD(sd, "7d"), (notw, notx), and7);
  And ( SD(sd, "8d"), (y, z), and8);
  And ( SD(sd, "9d"), (w, noty, notz), and9);

  Or (SD(sd, "1f"), (and1, and2), W);
  Or (SD(sd, "2f"), (and3, and4), X);
  Or (SD(sd, "3f"), (and5, and6), Y);
  Or (SD(sd, "4f"), (and7, and8, and9), Z);
  
  
}

