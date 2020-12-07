
/******************************************************************************
Name: Abhiram Durgaraju
PID: A46073985
Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
Purpose: Creates a counter and outputs 4 as hexadecimal to be final inputs for
w,x,y, and z. These 4 input, which were initially switches, are used to
display the PID via probes that make a Figure 8 pattern
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;
  Signal Strobe (1);
  Signal ResetA (1);
  Signal ResetB (1);
  
  

  // Replace with code to generate four input signals
 
  Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

  //Switch ( SD("1a"), w, 'w' );
  //Switch ( SD("2a"), x, 'x' );
  //Switch ( SD("3a"), y, 'y' );
  //Switch ( SD("4a"), z, 'z' );

  Not (SD("1b"), ResetA, ResetB);

  Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w,x,y,z));
  

  Probe ((SD("3c-4c"),"Output"), (w,x,y,z));
   

  circuits( SD("1e-4e"), w, x, y, z, Present, a, b, c, d, e, f, g);

  Probe ( (SD("1g"), "Present"), Present);
  Probe ( (SD("2g"), "a"), a);
  Probe ( (SD("3f"), "f"), f);
  Probe ( (SD("3h"), "b"), b);
  Probe ( (SD("4g"), "g"), g);
  Probe ( (SD("5f"), "e"), e);
  Probe ( (SD("6g"), "d"), d);
  Probe ( (SD("5h"), "c"), c);
   
    
    

  // Replace with code to display eight output signals
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10, and11;
  Signal and12, and13, and14, and15, and16;


  //All gates of each type are 
  
  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"3a"), x, notx );
  Not ( SD(sd,"5a"), y, noty );
  Not ( SD(sd,"7a"), z, notz );

  And ( SD(sd, "1c"), (notw, x), and1);
  And ( SD(sd, "2c"), (w, notx, noty), and2);
  And ( SD(sd, "3c"), (notw, y, z), and3);
  And ( SD(sd, "4c"), (notw, noty, notz), and4);
  And ( SD(sd, "8d"), (w, notx, notz), and16);
  And ( SD(sd, "5c"), (noty, notz), and5);
  And ( SD(sd, "6c"), (y, z), and6);
  And ( SD(sd, "7c"), (y, notz), and7);
  And ( SD(sd, "8c"), (x, noty), and8);
  And ( SD(sd, "9c"), (notx, z), and9);
  And ( SD(sd, "1d"), (notw, y, notz), and10);
  And ( SD(sd, "2d"), (notw, notx), and11);
  And ( SD(sd, "3d"), (noty, z), and12);
  And ( SD(sd, "4d"), (w, noty), and13);
  And ( SD(sd, "5d"), (x, y, notz), and14);
  And ( SD(sd, "6d"), (One, One), c); // generate a constant signal One
  And ( SD(sd, "7d"), (notx, notz), and15);
  
  
  
      
  

  Or ( SD(sd,"1e"), (and1, and2, and3, and4, and16), Present);
  Or ( SD(sd,"2e"), (notx, y, z), a);
  Or ( SD(sd,"3e"), (noty, notz), f);
  Or ( SD(sd,"4e"), (notx, and5, and6), b);
  Or ( SD(sd,"5e"), (w, and7, and8, and9), g);
  Or ( SD(sd,"6e"), (and15, and10), e);
  Or ( SD(sd,"7e"), (and11, and12, and13, and14), d);
  
  
  
  
  
  

  // Replace with declarations for any auxiliary Signals

  // Replace with circuit implementation (Not, And, Or gates)
}

