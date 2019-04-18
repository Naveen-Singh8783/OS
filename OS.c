#include<stdio.h>
void resoure_allocation(int e,int f,int g,int h); //method to allocate resources
void max_resource_need(int a,int b,int c,int d); //method for maximum resources required  
int allocation[10][10], max[10][10];
int main()
{
	int process=5;  //Total number of process
	int resource=3; //Total number of resources
	int need[10][10], Available_resource[10],i,j,k,initial[10],check=0,safe_sequence[10],z=0,count;

	for (i=0;i<process;i++)
	{
    	initial[i]=0;  //none of the process is satisfied initially
	}
	// Allocating the Resources to processes
	resoure_allocation(0,0,1,0);
	resoure_allocation(1,2,0,0);
	resoure_allocation(2,3,0,2);
	resoure_allocation(3,2,1,1);
	resoure_allocation(4,0,0,2);
	
	// Maximum Resource Required to processes
	max_resource_need(0,7,5,3);
	max_resource_need(1,3,2,2);
	max_resource_need(2,9,0,2);
	max_resource_need(3,2,2,2);
	max_resource_need(4,4,3,3);
	

	// Available Resource 
	Available_resource[0]=3;
	Available_resource[1]=3;
	Available_resource[2]=2;
	
	//Display allocated resource
	printf("Resource allocate\n");
	for(i=0;i<process;i++)
	{
		printf("P[%d]  ",i);
		for(j=0;j<resource;j++)
		{
			printf("%d  ",allocation[i][j]);
		}
		printf("\n");
	}
	
	// Display maximum Resource Requried
	printf("\nMaximum Resource Required\n");
	for(i=0;i<process;i++)
	{
		printf("P[%d]  ",i);
		for(j=0;j<resource;j++)
		{
			printf("%d  ",max[i][j]);
		}
		printf("\n");
	}
	
	//need of each process
	for(i=0;i<process;i++)
	{
    	for(j=0;j<3;j++)
    	{
    		need[i][j]=max[i][j]-allocation[i][j]; 
    	}
	}

    printf("\n");
    //Display needs of process
	for(i=0;i<process;i++) 
		{
    	printf("Need of P[%d] is: ",i);
    	for(j=0;j<resource;j++)
    	{
    		printf("%d ",need[i][j]);
    	}
    	printf("\n");
	}
	printf("\n");
	for(i=0;i<process;i++)
	{
    	for(j=0;j<process;j++) //for process
    	{
        	count=0;
        	for(k=0;k<resource;k++) //for resource
        	{
        		if(initial[j]==0 && need[j][k]<=Available_resource[k])  //need[j][k] means need of jth process's kth resource
        		{
            		Available_resource[k]=Available_resource[k]+allocation[j][k];
            		count++;
            		if(count==resource)  //if true means need for all the resources can be satisfied
            		{
                		initial[j]=1;  // process has been allocated resources hence initial array value
                		printf("Process %d has been allocated all required resources\n",j);
            
                		safe_sequence[z]=j;  // array sequence stores the safe sequence. jth process is added to safe sequence
                		z++;
            		}
        			continue;  //if need of one resource is satisfied then we check for next resource
        		}
        		break;  // if need  for any resource of a process can not be satisfied, break the loop and check the  
                      //need of next process
        	}
    	}
	}
	for(i=0;i<process;i++)
	{
    	if(initial[i]==0)
    	{
    		printf("\nsystem is in unsafe state\n");
    		check=1;
    		break;
   		}
    
	}
	if(check==0)
	{
		printf("\nSystem is in safe state\n");
		printf("\nSafe sequence is \n");
		for(i=0;i<process;i++)
		{
   			 printf("P[%d],",safe_sequence[i]);
		}
	}
	printf("\n");
	return 0;

}

void resoure_allocation(int e,int f,int g,int h)
{
	allocation[e][0]=f;
	allocation[e][1]=g;
	allocation[e][2]=h;
}

void max_resource_need(int a,int b,int c,int d)
{
	max[a][0]=b;
	max[a][1]=c;
	max[a][2]=d;
}
