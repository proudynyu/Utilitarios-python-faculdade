#!/usr/bin/env python
# coding: utf-8

# # High-Pass Filter
# ## Transfer Function
# ### Members:
#     Igor Henrique Lima Becker      4716039
#     Alvaro B. Domingues            4616002
#     Juvenil Aparecido dos Santos   4716044
# 
# *This document was made using Jupyter Notebook and Anaconda for Python*

# 1. **Find the Transfer Function from the filter below**
# 2. **Make a filter using a FC = 100Hz**
# 
#     *The cut off frequency function is: $\frac{1}{2{\pi}RC}$*
# 
# ![image.png](attachment:image.png)

# (1)
# 
# We know that:
# $${{Z_{C} = \frac{1}{sC}}\;\; and\;\; {Z_{R} = R}}$$
# 
# The input Impedance is:
# $${Z_{in} = Z_{R} + Z_{C}}$$
# 
# And the transfer function is:
# $${\frac{V_{o}}{V_{i}} = \frac{Z_{out}}{Z_{in}} }$$
# 
# For the transfer function we have:
# $${G(s) = \frac{Z_{out}}{Z_{in}}}$$
# 
# $${ \frac{Z_{out}}{Z_{in}} = \frac{R}{R + \frac{1}{sC} } = \frac{sCR}{sCR + 1} }$$
# 
# $${ G(s) = \frac{sCR}{sCR + 1} }$$

# (2)
# 
# $${f_{c} = 100Hz}$$
# 
# We will use a Resistor with 150Ohms
# $${R = 150\Omega}$$
# 
# With the value from the resistor, we can find the value for the capacitor:
# $${C = \frac{1}{2{\pi}R{f_{c}}}}$$

# In[12]:


import math

def getCapacitor(fc, r):
    return (1/(2*math.pi*fc*r))

fc = 100
r = 150

C = getCapacitor(fc, r)

print(f'Capacitor value: {C:.2}')


# In[19]:


from scipy import signal
import matplotlib.pyplot as plt

num = [C*r, 0]
dem = [C*r, 1]

sys = signal.TransferFunction(num, dem)
w, mag, phase = signal.bode(sys)

plt.figure()
plt.semilogx(w, mag)
plt.grid(True, linestyle='--', color='grey')
plt.figure()
plt.semilogx(w, phase)
plt.grid(True, linestyle='--', color='grey')
plt.show()


# *The .py and .ipynb can be found on []()
