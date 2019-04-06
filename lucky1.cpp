#include<stdio.h>
int main(){
	int i,j,k,n,head,hloc,phloc,a[20],temp,max,sum=0;
	printf("Enter no. of locations:");
	scanf("%d",&n);
	printf("Enter position of head:");
	scanf("%d",&head);
	printf("Enter privious Head location:");
	scanf("%d",&phloc);
	printf("Enter locations in Disk:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[n]=head;
	n=n+1;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	max=a[n];
	for(i=0;i<n;i++){
		if(head==a[i]){
			hloc=i;
			break;
		}
	}
	if(phloc<hloc){
		k=0;
		for(i=hloc;i<n;i++){
			printf("%d ---> ",a[i]);
			sum=sum+(a[i]-a[i-1]);
		}
		//sum=sum+(a[i]-a[hloc]);
		for(i=hloc-1;i>=0;i--){
			printf("%d ---> ",a[i]);
		}
		k=a[i]-a[hloc-1];
		sum=sum+(a[hloc-1]-a[0]);
	}
	else{
		k=0;
		for(i=hloc;i>=0;i--){
			printf("%d ---> ",a[i]);
		}
		sum=sum+(a[hloc-1]-a[0]);
		for(i=hloc+1;i<n;i++){
			printf("%d ---> ",a[i]);
		}
		k=a[hloc+1]-a[0];
		sum=sum+(a[i]-a[hloc+1])+k;
	}
	printf("The Total Distance travelled by Head:%d",sum);
}
