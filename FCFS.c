#include<stdio.h>
typedef struct{
    int order;
    int arrival_time;
    int burst_time;
    int count_burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int starting_time;
} Process;
void main(){
    int number_of_process;
    printf("Enter Number of Process: ");
    scanf("%d",&number_of_process);
    Process process[number_of_process];
    for(int i=0;i<number_of_process;i++){
        printf("Enter Process Order: ");
        scanf("%d",&process[i].order);
        printf("Enter Process Arrival Time: ");
        scanf("%d",&process[i].arrival_time);
        printf("Enter Process Burst Time: ");
        scanf("%d",&process[i].burst_time);
        process[i].count_burst_time = process[i].burst_time;
    }
    int time = 0;
    int process_counter = 0;
    while(process_counter<number_of_process){
        if(process[process_counter].count_burst_time==0){
            printf("Process P%d Terminated.\n",process_counter);
            process[process_counter].completion_time = time;
            process[process_counter].turnaround_time = time-process[process_counter].arrival_time;
            process[process_counter].waiting_time = process[process_counter].turnaround_time - process[process_counter].burst_time;
            process[process_counter].response_time = process[process_counter].starting_time - process[process_counter].arrival_time;
            process_counter+=1;
        }
        else{
            if(process[process_counter].arrival_time<=time){
                    if(process[process_counter].count_burst_time==process[process_counter].burst_time){
                        process[process_counter].starting_time = time;
                    }
                printf("Process P%d is running from %d to %d.\n",process_counter,time,time+1);
                process[process_counter].count_burst_time-=1;
                time+=1;
            }
            else{
                printf("No Process Running from %d to %d.\n",time,time+1);
                time+=1;
            }
        }
    }
    for(int i=0;i<number_of_process;i++){
        printf("Process P%d Detail: \n",i);
        printf("Arrival Time: %d\n",process[i].arrival_time);
        printf("Burst Time: %d\n",process[i].burst_time);
        printf("Completion Time: %d\n",process[i].completion_time);
        printf("Turnaround Time: %d\n",process[i].turnaround_time);
        printf("Waiting Time: %d\n",process[i].waiting_time);
        printf("Response Time: %d\n",process[i].response_time);
        printf("\n");
    }
}
/*Example Input: 
    4 0 0 2 1 1 2 2 5 3 3 6 4
*/
