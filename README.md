# Fixing-Spherical-Aberration
This program calculates the Z step correction factor due to a mismatch in the Refractive Indices (Spherical Aberration) between the objective's immerse medium (water, oil, etc) and the sample.

First, it calculates the Refractive Index (RI) of a sample (n<sub>2</sub>) given the refractive indices of the particles (n<sub>p</sub>) and the solvent (n<sub>s</sub>), by using the packing fraction ![{\varphi}](https://latex.codecogs.com/svg.latex?&space;{\varphi}) ,

![\Large n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}](https://latex.codecogs.com/svg.latex?\Large&space;n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}) 

After calculating the sample's RI n<sub>2</sub>, it uses the immersion medium RI n<sub>1</sub> (from the input in the header) and calculates the corrected step given a step in Z (the default is 0.25 in &mu;m).

The correction factor is calculated with 4 different approaches:

   1) Carlsson's correction
     (n<sub>2</sub>/n<sub>1</sub>)
   2) Visser's correction
     tan(sin<sup>-1</sup>(NA/n<sub>1</sub>))/tan(sin<sup>-1</sup>(NA/n<sub>2</sub>))
   3) Mean correction
   4) Median correction

The mean correction calculates the mean depth where 100 rays equally spaced along the radius of an objective’s front lens intersect the optical axis in the sample, and the median correction calculates the median intersection point.
