# Fixing-Spherical-Aberration
This program calculates the Z step correction factor due to a mismatch in the Refractive Indices (Spherical Aberration) between the objective's immerse medium (water, oil, etc) and the sample.

First, it calculates the Refractive Index (RI) of a sample (![{n_2}](https://latex.codecogs.com/svg.latex?&space;{n_2})) given the refractive indices of the particles (![{n_p}](https://latex.codecogs.com/svg.latex?&space;{n_p})) and the solvent (![{n_s}](https://latex.codecogs.com/svg.latex?&space;{n_s})), by using the packing fraction ![{\varphi}](https://latex.codecogs.com/svg.latex?&space;{\varphi}),

![\Large n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}](https://latex.codecogs.com/svg.latex?\Large&space;n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}).

After calculating the sample's RI ![{n_2}](https://latex.codecogs.com/svg.latex?&space;{n_2}), it uses the immersion medium RI ![{n_1}](https://latex.codecogs.com/svg.latex?&space;{n_1}) (from the input in the header) and calculates the corrected step given a step in Z (the default is 0.25 in ![{\mu}m](https://latex.codecogs.com/svg.latex?&space;{\mu}m)).

The correction factor is calculated with 4 different approaches:

   1) Carlsson's correction

      ![\Large \left(\frac{n_2}{n_1}\right)](https://latex.codecogs.com/svg.latex?\Large&space;\left(\frac{n_2}{n_1}\right))

   2) Visser's correction

     ![\Large \frac{\tan\left(\frac{NA}{n_1}\right)}{\tan\left(\frac{NA}{n_2}\right)}](https://latex.codecogs.com/svg.latex?\Large&space;\frac{\tan\left(\frac{NA}{n_1}\right)}{\tan\left(\frac{NA}{n_2}\right)})
   
   3) Mean correction
   
   4) Median correction

The mean correction calculates the mean depth where 100 rays equally spaced along the radius of an objective’s front lens intersect the optical axis in the sample, and the median correction calculates the median intersection point.
