import numpy as np
import math
import os 
x =int (input("Enter the number of subjects: "))
credit_hour=[]
grade=[]
point=[]
for i in range(x):
    c=input("Enter credit hour for subject "+str(i+1)+":")
    g=input("Enter the grade for subject "+str(i+1)+":")
    credit_hour.append(float(c))
    grade.append(g)
ch=np.sum(credit_hour)
for i in range(len(grade)):
 if grade[i]== 'A' :
    grade[i]=4.00
 elif grade[i]=='A-':
    grade[i]=3.67
 elif grade[i]=='B+':
    grade[i]=3.33
 elif grade[i]=='B':
    grade[i]=3.00
 elif grade[i]=='B-':
    grade[i]=2.67
 elif grade[i]=='C+':
    grade[i]=2.33
 elif grade[i]=='C':
    grade[i]=2.00
 elif grade[i]=='D':
    grade[i]=1.67
point=np.multiply(grade,credit_hour)
k=np.sum(point)
print("Total Credit Hours:",ch)
print("Total Credit Points:{:.2f}".format(k))
t=4.00*(np.sum(credit_hour))
p=(k/t)*4
print("Grade Point Average(GPA):{:.2f}".format(p))