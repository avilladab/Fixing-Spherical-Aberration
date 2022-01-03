# Fixing-Spherical-Aberration
This program calculates the Z step correction factor due to a mismatch in the Refractive Indices between the objective's immerse medium (water, oil, etc) and the sample.

First, it calculates the Refractive Index (RI) of a sample (n2) given the refractive indices of the particles (np) and the solvent (ns), by using the packing fraction phi,

n2 = phi*np + (1-phi)*ns

After calculating the sample's RI n2, it uses the immersion medium RI n1 (from the input in the header) and calculates the corrected step given a step in Z (the default is 0.25 in microns).

The correction factor is calculated with 4 different approaches:

   1) Carlsson's correction
   2) Visser's correction
   3) Mean correction
   4) Median correction
