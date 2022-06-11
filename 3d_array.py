import numpy as np
#taking the size of matrix (both matrix size must be the same)
i=int(input("Enter number of array :"))
j=int(input("Enter number of row :"))
k=int(input("Enter number of column :"))
text= ("Enter the number for row {} column {} array {} =")
R=i*j*k
#matrix 1
matrix1 = []
#getting value for matrix 1

for z in range (k):
  for x in range (i):
    for y in range (j):
        c=int(input(text.format(x+1,y+1,z+1)))
        matrix1.append(c)
array1=np.array(matrix1).reshape(i,j,k)
#showing the value of matrix 1
print ("matrix 1")
print(array1)

#matrix 2
matrix2 = []
#getting value for matrix 2
for z in range (k):
  for x in range (i):
    for y in range (j):
        arraynum2=int(input(text.format(x+1,y+1,z+1)))
        matrix2.append(arraynum2)
array2=np.array(matrix2).reshape(i,j,k)
print ("matrix 2")
print(array2)
print ("--------------------------------")
#showing the addition
print(array1, "\n+\n", array2)
sum=np.add(array1,array2)
print ("\n=\n")
print(sum)