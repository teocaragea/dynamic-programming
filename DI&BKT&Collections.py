# -*- coding: utf-8 -*-
"""
Created on Wed Jan 29 10:46:08 2020

@author: Teo
"""
#%%
l=[1,2,3,4]
l.insert(2,5)
print(l)
s1={1,2,3,4}
s2={4,2,5,6}
print(s1 & s2)
#%%
viorel={}
viorel[3]=2
viorel[2]=1
viorel[4]=69
print(viorel)
for item in viorel.keys():
    print(item, viorel[item])
#%%
    import math
    x=23
    a=11
    b=55
    if x in range(a,b):
        print("da")
gcd(6,12)
#%%
n=10
for i in range(0,n+1):
    for j in range(0,i):
        if j==i-1:
            print('c')
        else:
            print('c',end="")
#%%
ordinale= ["primul", "al doilea", "al treilea", "al patrulea", "al cincilea", "al saselea","al saptelea", "al optulea", "al noulea"]
x=123
x=str(x)
x=x[::-1]
print(x)   
#%%
def prim(x):
    for i in range(2,x):
        if x%i==0:
            return i
    return 0
print(prim(13))
l=[1,2,12,3,4,6,8]
i=0
while i<len(l):
    if l[i]%2==0:
        del l[i]
        i-=1
    i+=1
print(l)
#%%
aparitii={}
for c in list('ana are mere'):
    aparitii[c]=aparitii.get(c,0)+1
print(aparitii)
aparitii=sorted(aparitii.items(),reverse=True,lambda x:(x[1],x[0]))
print(aparitii)
#%%
s="ana are mere"
s=s.rsplit(" ")
for item in s:
  print(item)
#%%
x="ana"
y="mere"

l=[1,23,4,5]
numere=map(lambda x:x**2,l) 
print(list(numere)) 
#%%
my_strings = ['a', 'b', 'c', 'd', 'e']
my_numbers = [1,2,3,4,5]
results = list(zip(my_strings,
my_numbers))
print(results)
luni=["january","march","April"]
tsales=[500,200,400]
prodcost=[100,200,50]
profit=map(lambda x,y:x-y,tsales,prodcost)
profit=list(profit)
results=zip(luni,profit)
print(list(results))
#%%
f=open("fisier.txt",'r')
l=[]
s=f.readline()
s=s.split()
for element in s:
    l.append(int(element))
g=open("scrie.txt",'w')
for element in l:
    g.write(str(element))
#%%
f=open("test.txt",'r')
g=open("write.txt",'w')
count=0
for line in f:
    s=line
    s=s.split()
    for element in s:
        count=count+1
g.write(str(count))
#%%
f=open("test.txt",'r')
import datetime
import time
d=datetime.date(2019,11,24)
d=f.readline()
d=time.strptime(d,"%d-%B-%Y")

tday=datetime.date.today()
tdelta=datetime.timedelta(days=10)
print(tday-d)
#%%
f=open("test.txt",'r')
d=datetime.date(2000,11,24)
print(d)
time=datetime.timedelta(days=19)
tday=datetime.date.today()
altadata=d.replace(year=d.year+19)
print(altadata)
print(d+time)
#%%
import string
import time
import datetime
f=open("test.txt",'r')
n=int(f.readline())
angajati=[]
for i in range(n):
    mesaj=string.Template('$dn_dna $nume /n Data fiind vechimea Dvs in firma noastra de $ani_vechime si $luni_vechime, veti primi un voucher in valoare de $valoare lei pe care puteti sa il folositi pana la data de $data_lim /n Cu stima /n $nume_m')
    a={}
    a['CNP']=f.readline()
    a['CNP']=a['CNP'][:len(a['CNP'])-1]
    a['nume']=f.readline()
    a['nume']=a['nume'][:len(a['nume'])-1]
    a['data_ang']=f.readline()
    a['data_ang']=a['data_ang'][:len(a['data_ang'])-1]
    a['salariu']=f.readline()
    a['salariu']=a['salariu'][:len(a['salariu'])-1]
    angajati.append(a)
for x in angajati:
    if x['CNP'][0] in ['1','2']:
        an=1900+int(x['CNP'][1])*10+int(x['CNP'][2])
    else:
         an=2000+int(x['CNP'][1])*10+int(x['CNP'][2])
    if an<1960:
        angajati.remove(x)
print(angajati)
#%%
import time
import datetime
f=open("test.txt",'r')
s=f.readline()
print(s)
data_angj=time.strptime(s,'%d.%m.%Y')
data_angj=datetime.date(data_angj.tm_year,data_angj.tm_mon,data_angj.tm_mday)
azi=datetime.date.today()
m=(azi-data_angj).days
print
#%%
import time
import datetime
f=open("test.txt",'r')
s=f.readline()
print(s)
data=time.strptime(s,'%d.%m.%Y')
data=datetime.date(data.tm_year,data.tm_mon,data.tm_mday)
data2=datetime.timedelta(days=10)
print(data+data2)

#%%
data = 50
try:
 data = data/0
except :
 print('Cannot divide by 0 ', end= '')
else:
  print('Division successful ', end= '')
try:
  data = data/5
except:
  print('Inside except block ', end= '')
else:
  print('GFG', end = '') 
#%%

import math

def div(p,u):
    if u-p<2:
        return math.gcd(a[p],a[u])
    else:
        m=(p+u)//2
        r1=div(p,m)
        r2=div(m+1,u)
        r=math.gcd(r1,r2)
    return r
#%%
def cb(p,u):
     if u-p>=0:
         m=(p+u)//2
         if a[m]==m:
             return 1
         elif m<a[m]:
             return cb(p,m-1)
         else:
             return cb(m+1,u)
     else:
         return -1
a=[2,22,22,24,45]  
print(cb(0,4))
#%%
b=[2,3,5,6,1]
def divimp(p,u):
   if u-p<1:
       return b[p]
   else:
       m=(p+u)//2
       r1=divimp(p,m)
       r2=divimp(m+1,u)
       r=r1+r2
   return r
print(divimp(0,4))
#%%
a=[1000,78,23,7,120,8,380]
l=[1]*len(a)
for i in range(0,len(a)):
    for j in range(0,i):
        if a[i]>a[j]:
            if l[i]<l[j]+1:
                l[i]=l[j]+1
print(l)
#%%

def afi():
    for i in range(1,n):
        print(st[i])

def bkt(k,n):
    for i in range(0,n):
        st[k]=i
        if k==n:
            afi()
        else:
            bkt(k+1,n)
n=3
st=[0]*n
bkt(1,n)
#%%permutari
def afisare() :
    for i in range(1,n+1) :
        print(st[i], end = " ")
    print("\n")

def valid(k) :
    for i in range(1,k) :
        if st[i] == st[k] :
            return 0
    return 1

def bkt(k) :
    for i in range(1, n+1) :
        st[k] = i
        if (valid(k) == 1) :
            if k == n :
                afisare()
            else :
                bkt(k+1)

n = int(input())
st =[0]*(n+2)
bkt(1)
#%%produs cartezian
n=int(input())

def afi():
    for i in range(1,n+1):
        print(st[i],end=" ")

    print('\n')
def bkt(k):
    for i in range(1,n+1):
        st[k]=i
        if k==n:
            afi()
        else:
            bkt(k+1)
bkt(1)
print()
#%%aranjamente
n=5
p=2
def afi(p):
    for i in range(1,p+1):
        print(st[i],end=" ")
    print('\n')
def valid(k):
    for i in range(1,k):
        if st[i]==st[k]:
            return 0
    return 1
def bkt(k):
    for i in range(1,n+1):
       st[k]=i
       if valid(k)==1:
           if k==p:
               afi(k)
           else:
               bkt(k+1)
bkt(1)
#%%combinari
n=5
p=3
def afi(k):
    for i in range(1,k+1):
        print(st[i],end=" ")
    print('\n')
def valid(k):
    for i in range(1,k):
        for j in range(i+1,k+1):
            if st[i]>=st[j]:
                return 0
    return 1
def bkt(k):
    for i in range(1,n+1):
        st[k]=i
        if valid(k)==1:
            if k==p:
                afi(k)
            else:
                bkt(k+1)
bkt(1)
  
      
           



















