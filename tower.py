def tower(n,src,temp,des):
    if(n==1):
        print("move disc 1 from",src,"to",des)
    else:
        tower(n-1,src,des,temp)
        print("move disc",n," from",src,"to",des)
        tower(n-1,temp,src,des)
n=int(input("enter the number"))
tower(n,"a","b","c")
