#include<stdio.h>
int main(){
	int i,j,k,n,head,hloc,phloc,a[20],disk[5000],temp,max,min,l,d=0;
	for(i=0;i<5000;i++){
		disk[i]=i;
	}
	max=disk[4999];
	min=disk[0];
	printf("Disk Drive having 5000 Cylinders numberd 0 to 4999");
	printf("\nEnter no. of locations:");
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
	for(i=0;i<n;i++){
		if(head==a[i]){
			hloc=i;
			break;
		}
	}
	if(phloc<a[hloc]){
		for(i=hloc;i<n;i++){
			j = 0;
			printf("%d ---> ",a[i]);
			j = (a[i]-head);
			d += j;
			head = a[i];
		}
		printf("4999 ---> ");
		l=max-head;
		k=max-a[hloc-1];
		head=a[hloc-1];
		for(i=hloc-1;i>=0;i--){
			j = 0;
			printf("%d ---> ",a[i]);
			j = (head-a[i]);
			d += j;
			head = a[i];
		}
	}
	else{
		for(i=hloc;i>=0;i--){
			j = 0;
			printf("%d ---> ",a[i]);
			j = (head-a[i]);
			d += j;
			head = a[i];
		}
		printf("0 ---> ");
		l=head-min;
		k=a[hloc+1]-min;
		head=a[hloc+1];
		for(i=hloc+1;i<n;i++){
			j = 0;
			printf("%d ---> ",a[i]);
			j = (a[i]-head);
			d += j;
			head = a[i];
		}
	}
	printf("\nThe Total Distance travelled by Head:%d",d+k+l);
}
