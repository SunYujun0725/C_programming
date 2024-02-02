#include <stdio.h>
#include <stdlib.h>
void myfun_r(int pos, int start, int data[], int n, int chosen[], int r, int np[]) {
    if(pos==r){
        for(int i=0; i<r; i++){
            data[chosen[i]]++;
        }
        for(int i=0; i<n; i++){
            if(data[i]%np[i]!=0){
                for(int i=0; i<n; i++){
        			data[i]=0;
   	 			}
                return;
            }else{
                data[i]/=np[i];
            }
        }
        for(int i=0; i<n; i++) {
       	 	printf("%d ", data[i]);
    	}
    	printf("\n");
        for(int i=0; i<n; i++){
        	data[i]=0;
   	 	}
        return;
    }
    for(int i=start; i<n; i++){
        chosen[pos]=i;
        myfun_r(pos+1,i,data,n,chosen,r,np);
    }
}
int main() {
    
    int n,m;
    scanf("%d",&n);
    if(n<1 || n>10) return 0;
    int* np = (int*) malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d",np+i);
        if(*(np+i)<1 || *(np+i)>10000) return 0;
    }
    scanf("%d",&m);
    if(m<0|| m>10000) return 0;
    
    int* data = (int*) malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        data[i]=0;
   	}
    int* chosen = (int*) malloc(sizeof(int)*m);
    for(int i=0; i<m; i++){
        chosen[i]=0;
   	}
    myfun_r(0,0,data,n,chosen,m, np);
    
    free(np);
    free(data);
    free(chosen);
    return 0;
}


