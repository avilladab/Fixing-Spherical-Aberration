# Fixing-Spherical-Aberration
This program calculates the Z step correction factor due to a mismatch in the Refractive Indices (Spherical Aberration) between the objective's immerse medium (water, oil, etc) and the sample.

First, it calculates the Refractive Index (RI) of a sample (n<sub>2</sub>) given the refractive indices of the particles (n<sub>p</sub>) and the solvent (n<sub>s</sub>), by using the packing fraction &phi;,

![n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}](https://latex.codecogs.com/svg.latex?&space;n_{2}={\varphi}n_{p}+(1-{\varphi})n_{s}).

After calculating the sample's RI n<sub>2</sub>, it uses the objective's immersion medium RI n<sub>1</sub> and the objective's Numerical Aperture (NA) from the input in the header and calculates the correction factor and the corrected step &Delta;z<sub>r</sub> given a mechanical step in Z &Delta;z<sub>m</sub> (the default is 0.25 in &mu;m).

The correction factor is calculated with 4 different approaches:

1) Carlsson's correction:

<div align='center'>![\left(\frac{n_2}{n_1}\right)](https://latex.codecogs.com/svg.latex?&space;\left(\frac{n_2}{n_1}\right))</div>

2) Visser's correction:

![\frac{\tan\left(\sin^{-1}\left(\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{NA}{n_2}\right)\right)}](https://latex.codecogs.com/svg.latex?&space;\frac{\tan\left(\sin^{-1}\left(\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{NA}{n_2}\right)\right)})

3) Mean correction:

![\frac{1}{100}\sum_{k=1}^{100}\frac{\tan\left(\sin^{-1}\left(\frac{k}{100}\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{k}{100}\frac{NA}{n_2}\right)\right)}](https://latex.codecogs.com/svg.latex?&space;\frac{1}{100}\sum_{k=1}^{100}\frac{\tan\left(\sin^{-1}\left(\frac{k}{100}\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{k}{100}\frac{NA}{n_2}\right)\right)})

4) Median correction:

![\frac{\tan\left(\sin^{-1}\left(\frac{1}{2}\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{1}{2}\frac{NA}{n_2}\right)\right)}](https://latex.codecogs.com/svg.latex?&space;\frac{\tan\left(\sin^{-1}\left(\frac{1}{2}\frac{NA}{n_1}\right)\right)}{\tan\left(\sin^{-1}\left(\frac{1}{2}\frac{NA}{n_2}\right)\right)})

The mean correction calculates the mean depth where 100 rays equally spaced along the radius of an objective’s front lens intersect the optical axis in the sample, and the median correction calculates the median intersection point.
