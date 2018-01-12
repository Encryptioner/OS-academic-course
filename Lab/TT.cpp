#include<iostream>
        using namespace std;
        int main()
        {
          int a[4][5],stack[4],gc[4][30];  //a for Process details, gc for Gantt Chart
          int np,t,sp=0,i,j,p=0,tp=4,tot=0,k,sw; //np for no of Process,sp for stackpointer, tp top stackpointer
          l1:
          cout<<"Enter Number Of Process(Max 4):";
          cin>>np;              //Get Number of process
          if(np>4)
          {
            goto l1;
          }
          tp=np-1;              //set total stack elements
          for(i=0;i<np;i++)
          {
               a[i][0]=i+1;     //store process number
               cout<<"For Process "<<i+1<<"\nEnter Arrival Time:";
               cin>>a[i][1];    //store process Arrival Time
               cout<<"Enter Execution Time:";
               cin>>a[i][2];     //store Execution time
               a[i][3]=0;         //set process Waiting time zero
               a[i][4]=a[i][2];  //set remaining Execution time
               stack[i]=a[i][0]; //store process number in stack
               tot+=a[i][2];
          }
          cout<<"\nEnter Quantem time:";
          cin>>t;
          for(i=0;i<tot;i++)
          {
            while(a[stack[sp]-1][4]==0)     //This loop remove completed Proceess from stack
            {
                for(int v=sp;v<tp;v++)
                {
                    stack[v]=stack[v+1];
                }
                tp--;
                p=0;
                if(sp>tp)
                sp=0;
            }
            if(p==t)   //this loop will assign next process to CPU when Quantem time complete
            {
              p=0;
              sp++;
              if(sp>tp)
              {
                sp=0;
              }
            }
            for(j=0;j<np;j++)  //this loop stores Proceess Activity
            {
              if(a[j][1]>i)  //this store status in Gantt Chart which is process not Arrived
              {
                gc[j][i]=2; //2 represent process is not Arrived
              }
              else if(a[j][1]<=i && a[j][0]!=stack[sp] )  //this stores status in Gantt Chart which process is Waiting
              {
                 if(a[j][4]!=0)
                 {
                    gc[j][i]=0; //0 represent process is Waiting
                    a[j][3]++;
                 }
                 else
                 {
                    gc[j][i]=2;  //2 represent process is not Arrived
                 }
              }
              if(a[j][1]<=i && a[j][0]==stack[sp])  //store status that process is executing
              {
                  gc[j][i]=1;  //1 Represents process Execution

              }
            }
            a[stack[sp]-1][4]--;  //decrement remaining Execution time of an Process
            p++; //increment Quantem Execution time
          }
          cout<<endl<<"Process Waiting time:"<<endl;
          for(i=0;i<np;i++) //Print waiting time of Processes
          {
            cout<<"P"<<i+1<<": "<<a[i][3];
            cout<<endl;
          }
          cout<<endl;
          for(i=0;i<np;i++)  //Pront Gantt Chart
          {
            cout<<"Process P"<<i+1<<" :";
            for(j=0;j<tot;j++)
            {
               if(gc[i][j]==0)  //0 represent process is Waiting
               {
                  cout<<"-|";
               }
               else if(gc[i][j]==1)  //1 Represents process is Execution
               {
                  cout<<"*|";
               }
               else if(gc[i][j]==2)  //2 Represents Proceess is completed or not Arrived
               {
                  cout<<" |";
               }
            }
            cout<<endl;
          }
          return 0;
        }
