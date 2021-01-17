# Problema spectacolelor

spectacole = []
n= int(input("nr spectacole = "))
for i in range(n):
    print("     Spectacolul",i + 1,": ")
    start = int(input("ora inceperii: "))
    final = int(input("ora final: "))
    spectacole.append((start,final))
    
print(spectacole)


def criteriu(x, y):    
    return x[1] - y[1]
spectacole_ordonate = sorted(spectacole, key = lambda x: x[1])
print(spectacole_ordonate)

final_anterior = -1
for s in spectacole_ordonate:
    if s[0] >= final_anterior:
        print(s[0],s[1])
        final_anterior = s[1]
    
#%%
# Problema rucsacului
G = int(input("capacitate rucsac:"))
o = int(input("nr obiecte:"))
obiecte = []
for i in range(o):
    print("    Ob. nr.", i + 1)    
    c = int(input("Castig ob. 1: "))
    g = int(input("Greutate ob. 1: "))
    obiecte.append((c,g))
    
print(obiecte)
obiecte_ordonate = sorted(obiecte, key = lambda x: x[0] / x[1], reverse = True)

print(obiecte_ordonate)    

sol = []

for x in obiecte_ordonate:
    if x[1] <= G:
        sol.append(x[1])
        G = G - x[1]
    else:
        sol.append(G / x[1])
        for i in range(len(sol),o):
            sol.append(0)
        break
                    
print(sol)

#%%
# Asezarea textelor pe o banda
n = int(input("numarul textelor: "))
print("Dati lungimile textelor: ")
lungimi = []
for i in range(n):
    lungimi.append((i,int(input())))
    
lungimi_ordonate = sorted(lungimi, key = lambda x: x[1])

print(lungimi_ordonate)

#%%
# Maximizarea unei expresii
import numpy as np

m = int(input("m="))
n = int(input("n="))
print("Dati elementele m. A:")
A = []
for i in range(m):
    A.append(int(input()))
 
print("Dati elementele m. B:")
B = []
for i in range(n):
    B.append(int(input()))

A = sorted(A, reverse = True)
B = sorted(B, reverse = True)
print("A=",A)
print("B=",B)

if min(A) >=0:
    B1 = B[:m]
    E = np.inner(A,B1)
    
elif max(A) < 0:
    A = A[::-1]
    # print(A)
    B1 = B[:- m - 1:-1]
    # print("B1=",B1)
    E = np.inner(A,B1)
    
else:
    for i in range(m-1, -1, -1):
        if A[i] > 0:
            break
    A1 = A[:i + 1]
    A2 = A[i + 1:]
    A2 = A2[::-1]
    B2 = B[:i + 1]
    B1 = B[: - len(A2) - 1: -1]
    '''print("A1=",A1)
    print("A2=",A2)
    print("B1=",B1)
    print("B2=",B2)'''
    E = np.inner(A1, B2) + np.inner(A2, B1)

    
print(E)

#%%
# Trasee de lungime maxima

t = []
s = []
n = int(input("nr de linii"))
for i in range(n):
    print("Dati elementele liniei",i)
    l = []
    for j in range(i + 1):
        l.append(int(input()))
    t.append(l)
    s.append(l)

for i in range(n - 2,-1,-1):
    for j in range(i + 1):
        t[i][j] = t[i][j] + max(t[i + 1][j],t[i + 1][j + 1])
print("Matricea t:")      
print(t)

print("Traseul: ")
print(0, 0)
j = 0
for i in range(0,n - 1):
    if t[i + 1][j] < t[i + 1][j + 1]:
        j = j + 1
    print(i + 1, j)
        
#%%
# Subsir crescator de lungime maxima

n = int(input("n="))
print("Dati elementele sirului:")
L = []
for i in range(n):
    L.append(int(input()))
    
lung = [1] * n
maxim = 1
indice_inceput_sir = n-1

for i in range(n - 2, -1,-1):
    for j in range(i + 1,n):
        if lung[j] + 1 > lung[i] and L[i] < L[j]:
            lung[i] = lung[j] + 1
            if lung[i]> maxim:
                indice_inceput_sir = i
                maxim = lung[i]
                

print(lung)
indice = indice_inceput_sir
lungime = maxim - 1
print(L[indice], end = " ")


for k in range(indice_inceput_sir + 1,n):
    if L[k] > L[indice] and lung[k] == lungime:
        print(L[k], end = " ")
        indice = k 
        lungime = lungime - 1
