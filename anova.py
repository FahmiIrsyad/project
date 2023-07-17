from scipy.stats import f
import statistics
alpha = 0.05
list1 = [1207,7,2022,374,139,29,702,418,69,930,5839,340,740,3511,29,74,6,2,843,239,1104,1,295,1205,20,6280,171,335]
list2 = [1886,8,2231,1050,175,15,784,564,76,1095,12020,307,602,4967,4,89,8,2,1485,243,1762,2,385,2691,20,11416,100,524]
list3 = [1899,30,3530,1512,297,40,1283,656,98,1204,10741,426,699,5496,79,142,13,8,1931,378,1354,0,782,5024,34,11097,243,712]

variance1 = statistics.variance(list1)
variance2 = statistics.variance(list2)
variance3 = statistics.variance(list3)

mean1 = statistics.mean(list1)
mean2 = statistics.mean(list2)
mean3 = statistics.mean(list3)

total = list1 + list2 +list3
dfn = len([list1,list2,list3])-1
dfd = len(total)-len([list1,list2,list3])
GM = sum(total)/len(total)


SSb = 28*((mean1-GM)**2+(mean2-GM)**2+(mean3-GM)**2)
MSb = SSb/dfn

SSw = 27*(variance1+variance2+variance3)
MSw = SSw/dfd

f_test_value = MSb/MSw

f_crit = f.ppf(1-alpha,dfn,dfd)

print("mean for 2018:",mean1)
print("mean for 2019:",mean2)
print("mean for 2020:",mean3)
print("variance for 2018:",variance1)
print("variance for 2019:",variance2)
print("variance for 2020:",variance3)
print("grand mean:",GM)
print("critical value:",f_crit)
print("test value:",f_test_value)
if f_test_value<f_crit:
    print("null hypothesis accepted")
else:
    print("null hypothesis rejected")


 