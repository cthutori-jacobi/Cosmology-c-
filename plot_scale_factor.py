import numpy as np
import matplotlib.pyplot as plt

# Chargement des données (2 colonnes : t, a)
data = np.loadtxt("scale_factor.dat")

time = data[:, 0]          # temps cosmologique
scale_factor = data[:, 1]  # facteur d’échelle a(t)

# Tracé
plt.figure()
plt.plot(time, scale_factor)
plt.xlabel("Temps t (unités de H0⁻¹)")
plt.ylabel("Facteur d’échelle a(t)")
plt.title("Expansion cosmologique (équation de Friedmann)")
plt.grid()

plt.show()