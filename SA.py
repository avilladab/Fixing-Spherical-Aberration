# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 12:39:27 2022

@author: Alejandro
"""
from math import tan,asin

phi=0.3
Pz=0.25
NA=1.4
n1=1.515
np=1.4987
ns=1.4893
km=100

n2=phi*np+(1.0-phi)*ns
print("Sample packing fraction = %.2f, non corrected Z step: Dz_mech = %lf" % (phi,Pz))
print("Particle's RI = %lf, solvent's RI = %lf" % (np,ns))
print("Sample RI = %lf, oil RI = %lf" % (n2,n1))
d=n2/n1;
print("\nCarlsson's correction:")
print("Dz_real = %lf" % (Pz*d))
print("Correction factor = %lf" % d)
d=tan(asin(NA/n1))/tan(asin(NA/n2))
print("\nVisser's correction:")
print("Dz_real = %lf" % (Pz*d))
print("Correction factor = %lf" % d)
d=0.0
for k in range (1,km+1):
  d+=tan(asin(k*NA/(km*n1)))/tan(asin(k*NA/(km*n2)))
d=d/km
print("\nMean correction:")
print("Dz_real = %lf" % (Pz*d))
print("Correction factor = %lf" % d)
d=tan(asin(0.5*NA/n1))/tan(asin(0.5*NA/n2))
print("\nMedian correction:")
print("Dz_real = %lf" % (Pz*d))
print("Correction factor = %lf" % d)