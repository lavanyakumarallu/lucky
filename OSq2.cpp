#include<stdio.h>
struct process{
	int i,pid,prty,at,bt,rt;   // process ID, Priority, Arrival Time, Burst time, Responce Time
};
struct process q1[20],q2[20];
int f1=-1,f2=-1,r1=-1,r2=-1;
void cp(int n,struct process p[]){
	int i;
	for(i=0;i<n;i++){
		printf("Enter Process Id :");
		scanf("%d",&p[i].pid);
		printf("Enter Process Arrival Time :");
		scanf("%d",&p[i].at);
		printf("Enter Process Burst Time :");
		scanf("%d",&p[i].bt);
		printf("Enter Process Priority :");
		scanf("%d",&p[i].prty);
		p[i].rt=p[i].bt;
	}
}
void q1push(struct process p){
	if(f1==-1)
		f1=0;
	r1+=1;
	q1[r1]=p;
}
void q2push(struct process p){
	if(f2==-1)
		f2=0;
	r2+=1;
	q2[r2]=p;
}
void q1pop(){
	f1+=1;
}
void q2pop(){
	f2+=1;
}
struct process q1f(){
	return q1[f1];
}
struct process q2f(){
	return q2[f2];
}
void aptq(int n, struct process p[]){
	int i;
	for(i=0;i<n;i++){
		if(p[i].prty==1){
			q1push(p[i]);
		}
		else if(p[i].prty==0){
			q2push(p[i]);
		}
	}
}
void ppq(){                 // Print Processes In Queues
	int i;
	printf("\nProcess In Student Queue :");
	for(i=0;i<=r1;i++){
		printf("p%d",q1[i].pid);
	}
	printf("\n\nprocess In Teacher Queue :");
	for(i=0;i<=r2;i++){
		printf("p%d",q2[i].pid);
	}
	printf("\n");
}
void rr(int n,struct process p[]){
	int i,t,tq=4,r=n,f=0,swt=0,stat=0;       // time , Time Quantum , remain , flag , Waiting Time , Turn Around Time
	float sawt=0,satat=0;           // Student Average Waiting Time and Student Average Turn Around Time
	printf("\n\n");
	printf("Process\t\tWaiting Time\tTurn Around Time\n\n");
	for(t=0,i=0;r!=0;){
		if((p[i].rt<=tq) && (p[i].rt)>0){
			t+=(p[i].rt);
			f=1;
		}
		else if((p[i].rt)>0){
			(p[i].rt)-=tq;
			t+=tq;
		}
		if((p[i].rt)==0 && f==1){
			r--;
			printf("Process[%d]\t\t%d\t\t%d\n",p[i].pid,t-((p[i].at)-(p[i].bt)),t-(p[i].at));
			swt=swt+t-(p[i].at)-(p[i].bt);
			stat=stat+t-(p[i].at);
			f=0;
		}
		if(i==n-1)
			i=0;
		else if((p[i+1].at)<=t)
			i++;
		else
			i=0;
	}
	sawt=(swt)/n;
	satat=(stat)/n;
	printf("\nAverage Waiting Time of Students = %f\n",sawt);
	printf("\nAverage Turn Around Time of Students = %f\n",satat);
}
void fcfs(int n,struct process p[]){
	int i,twt=0,ttat=0,at[20],wt[20],tat[20];
	float tawt=0,tatat=0;
	wt[0]=0;
	tat[0]=q2[f2].bt;
	at[0]=q2[f2].bt+q2[f2].at;
	for(i=1;i<n;i++){
		at[i]=at[i-1]+p[i].bt;
		tat[i]=at[i]-p[i].at;
		wt[i]=tat[i]-p[i].bt;
	}
	for(i=0;i<n;i++){
		twt+=wt[i];
		ttat+=tat[i]; 
	}
	printf("\n");
	printf("\t\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<n;i++){
		printf("\nProcess[%d]\t\t%f\t\t%f\n",p[i].pid,wt[i],tat[i]);
	}
	tawt=(twt)/n;
	tatat=(ttat)/n;
	printf("\nAverage Teacher Waiting Time =%f ",tawt);
	printf("\nAverage Teacher Turn Around Time =%f ",tatat);
}
void sq2(){
	rr(r1+1,q1);
}
void sq1(){
	fcfs(r2+1,q2);
}
void time(){
	float sawt,tawt,satat,tatat;
	printf("\nTotal Average Waiting Time = %f",sawt+tawt);
	printf("\nTotal Average Turn Around Time = %f",satat+tatat);
}
int main(){
	int n,i;
	printf("Enter Number of processes:");
	scanf("%d",&n);
	struct process p[n];
	cp(n,p);
	aptq(n,p);
	ppq();
	sq1();
	sq2();
	//printf("\nProcess ID:\tArrival Time:\tBurst Time:\tPriority:");
	for(i=0;i<n;i++){
		printf("\nPID %d\t\tAT %d\t\tBT %d\t\tPRIOTY%d\n",p[i].pid,p[i].at,p[i].bt,p[i].prty);
	}
	printf("\n\n");
	time();
}
