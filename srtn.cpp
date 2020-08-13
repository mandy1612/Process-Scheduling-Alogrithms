#include<bits/stdc++.h>
using namespace std;

int main() {
  int arrivaltime[] = {0,1,2,3,4};
  int bursttime[] = {3,6,4,7,2};
  int n = sizeof(arrivaltime)/sizeof(arrivaltime[0]);
  int x[n];
  int waiting[n],turnaround[n],completion[n];
  int i,j,smallest,count=0,time;
  double avg=0,tt=0,end;
  // printf("\nEnter the number of Processes: ");
  // scanf("%d",&n);
  // for(i=0;i<n;i++) {
  //   printf("\nEnter arrival time of process %d : ",i+1);
  //   scanf("%d",&arrivaltime[i]);
  // }
  // for(i=0;i<n;i++)
  // {
  //   printf("\nEnter burst time of process %d : ",i+1);
  //   scanf("%d",&bursttime[i]);
  // }
  for(i=0;i<n;i++)
    x[i]=bursttime[i];  
    bursttime[n-1]=9999;
    for(time=0; count!=n; time++){
      smallest=n-1;
      for(i=0; i<n; i++)
      {
          if(arrivaltime[i]<=time && bursttime[i]<bursttime[smallest] && bursttime[i]>0 )
              smallest=i;
      }
      bursttime[smallest]--;
      if(bursttime[smallest]==0){
        count++;
        end=time+1;
        completion[smallest] = end;
        waiting[smallest] = end - arrivaltime[smallest] - x[smallest];
        turnaround[smallest] = end - arrivaltime[smallest];
      }
  }
  cout<<"P Id \t Burst Time \t Arrival Time \tWaiting Time \tTurn Around Time\tCompletion Time";
  for(i=0;i<n;i++){
    printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],arrivaltime[i],waiting[i],turnaround[i],completion[i]);
    avg = avg + waiting[i];
    tt = tt + turnaround[i];
  }
  printf("\n\nAverage waiting time = %lf\n",avg);
  printf("Average Turnaround time = %lf",tt);
  return 0;
}