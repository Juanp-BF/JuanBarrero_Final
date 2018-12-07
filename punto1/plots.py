import numpy as np
import matplotlib.pyplot as plt

MC_1 = np.loadtxt('numeros_0.dat')
MC_2 = np.loadtxt('numeros_1.dat')
MC_3 = np.loadtxt('numeros_2.dat')
MC_4 = np.loadtxt('numeros_3.dat')
MC_5 = np.loadtxt('numeros_4.dat')
MC_6 = np.loadtxt('numeros_5.dat')
MC_7 = np.loadtxt('numeros_6.dat')
MC_8 = np.loadtxt('numeros_7.dat')

MCMCs = [MC_1, MC_2, MC_3, MC_4, MC_5, MC_6,MC_7,MC_8]  

mu = 0.0
sigma = 1.0
x = np.arange(-5, 5, 0.1)

plt.figure()
plt.title('Sampling')
plt.plot(x, np.exp(-(x-mu)*2/(2*sigma*2))/(sigma*np.sqrt(2*np.pi)), linewidth=2, color='darkgreen')
for i in MCMCs:
    plt.hist(i, bins=100, normed=True, color='blue')
plt.savefig("MCMC_Sampling.pdf")
