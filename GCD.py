def hcf(a,b):
    if(b==0):
        return a
    else:
        return hcf(b,a%b)
n=int(input("enter a"))
m=int(input("enter b"))
print(hcf(n,m))
