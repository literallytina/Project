#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Dept.: [EIE]
GroupID: [TRN001]
Name: [I-chen Fang]
Student ID: [19084469D]
"""

import numpy as np
from numpy.polynomial import polynomial as P
import matplotlib.pyplot as plt

print('Q1')

plt.figure()

plt.subplot(2,2,1)
a_x = np.arange(-2,2)
a_y = 3*(a_x)**3 - 1.5*(a_x)**2 + 5
plt.plot(a_x,a_y,'-b')
plt.xlabel("x = -2 to 2")
plt.ylabel('$3x^3 - 1.5x^2 + 5$')
plt.title('Q1.a')

plt.subplot(2,2,2)
b_x = np.arange(-np.pi,2*np.pi)
b_y = np.sin(b_x) + (np.cos(b_x))**2
plt.plot(b_x,b_y,'-b')
plt.xlabel("x = -$\pi$ to 2$\pi$ ")
plt.ylabel('$sin(x) + cos(x)^2$')
plt.title('Q1.b')

plt.subplot(2,2,3)
c_x = np.arange(-2,2)
c_y = (c_x)*np.exp(c_x)
plt.plot(c_x,c_y,'-b')
plt.xlabel("x = -2 to 2")
plt.ylabel('$xe^x$')
plt.title('Q1.c')

plt.subplot(2,2,4)
d_x = np.arange(-2,4)
d_y = np.sin(np.exp(d_x))
plt.plot(d_x,d_y,'-b')
plt.xlabel("x = -2 to 4")
plt.ylabel('$sin(e^x)$')
plt.title('Q1.d')

plt.subplots_adjust(wspace=0.6,hspace=0.6)
plt.show()


print('Q2')

plt.figure()

x=[3.2, 6.1, 15.6, 29.7, 51.2, 77.5, 112.4]
y=[10, 20, 60, 131, 250, 10, 525]

plt.plot(x, y, '-b.')
plt.title('Q2. The Conveyor Capacity to the Motor Angular Velocity Test')
plt.xlabel("Capacity (kg/s)")
plt.ylabel("Angular Velocity (RPM)")

plt.show()


print('Q3')

plt.figure()

x = [12, 37, 87, 70, 70, 19, 45, 59, 91, 21, 25, 27, 76, 46, 46, 51, 22, 80, 30, 23,\
 48, 68, 31, 60, 41, 44, 77, 65, 23, 57, 38, 76, 18, 22, 47, 35, 91, 51, 65, 56,\
 69, 45, 75, 23, 67, 28, 58, 21, 53, 21, 78, 75, 68, 75, 29, 30, 32, 58, 95, 80]
    
plt.subplot(2,1,1)
plt.hist(x, bins=10, rwidth=0.8) 
plt.title('Q3.a Mark Distribution of the Test')
plt.xlabel('Range of Mark')
plt.ylabel('Count')

plt.subplot(2,1,2)
plt.hist(x, bins=10, range=[0, 100], rwidth=0.8)
plt.title('Q3.b Mark Distribution of the Test')
plt.xlabel('Range of Mark')
plt.ylabel('Count')

plt.subplots_adjust(wspace=0.6,hspace=0.6)
plt.show()


print('Q4')

A=np.array(([1,6,8],[2,4,1],[4,8,6]))
print('a')
print(np.round(np.linalg.det(A), 2))
print('\n')

print('b')
print(np.round(np.linalg.inv(A), 2))
print('\n')

print('c')
print(np.round(A.prod(axis=1), 2))
print('\n')

print('d')
print(np.round(A.cumsum(axis=0), 2))
print('\n')


print('Q5')
A=(([-1,3,0],[3,4,-4],[-20,-12,5]))
C=(([-72],[-4],[-50]))

invA=np.linalg.inv(A)
X=np.matmul(invA,C)
print(np.round(X, 2))
print('\n')


print('Q6')
f=P.Polynomial([48,-14,1])
g=P.Polynomial([-102,31,19,-9,1])

print('a')
print(f.roots())
print(g.roots())
print('\n')

print('b')
F=[48,-14,1]
G=[-102,31,19,-9,1]
q, r=P.polydiv(G,F)
print(f"quotient: {q} \t remainder: {r}")
print('\n')

print('c')
m=P.polymul(F,G)
print(m)



