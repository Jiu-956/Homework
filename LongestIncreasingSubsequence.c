#include<stdio.h>
int a[10000000],demo[10000000];
int f(int n,int i){
    if(demo[i]!=0){
        return demo[i];
    }
    if(i==n){
        demo[i]=1;
        return 1;
    }
    int len=1;
    for(int j=i+1;j<=n;j++){
        if(a[j]>a[i]){
            len=len>f(n,j)+1?len:f(n,j)+1;
        }
    }
    demo[i]=len;
    return len;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int t=1;
    for(int i=1;i<=n;i++){
        if(f(n,i)>t){
            t=f(n,i);
        }
    }
    printf("%d",t);
}