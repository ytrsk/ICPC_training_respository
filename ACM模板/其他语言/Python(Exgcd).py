m=[0]
r=[0]
x=0
y=0
def exgcd(a,b) :
    global x
    global y
    gcd=0
    if b==0:
        x=1
        y=0
        return a
    else:
        gcd=exgcd(b,a%b)
        x,y=y,x
        y-=x*(a//b)
    return gcd
def powm(a,b,mod):
    ans=0;
    while(b):
        if b%2:
            ans=(ans+a)%mod
        a=(a*2)%mod
        b=b//2
    return (ans+mod)%mod
def exchina(n):
    global x
    global y
    tot=m[1]
    ans=r[1];
    i=2
    while i<=n :
        a=tot
        b=m[i]
        c=(r[i]-ans%m[i]+m[i])%m[i]
        gcd=exgcd(a,b)
        if c%gcd!=0:
            return -1
        x=powm(x,c//gcd,b//gcd)
        ans+=x*tot
        tot*=(b//gcd)
        ans=(ans%tot+tot)%tot
        i=i+1
    return ans
n,mm=input().split(" ")
n=int(n)
mm=int(mm)
i=1
while i<=n :
    xx,yy=input().split(" ")
    xx=int(xx)
    yy=int(yy)
    m.append(xx)
    r.append(yy)
    i+=1
ans=exchina(n)
if ans==-1:
    print("he was definitely lying")
elif ans<=mm :
    print(ans);
else :
    print("he was probably lying");
