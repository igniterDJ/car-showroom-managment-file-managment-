#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ind_cost[10],required[10],slno=0,recp=2354;
float cartax=0.5;
//Database of customer
struct customer{
    char cust_name[30];
    char cust_carno[10];
    int cust_time;
    int cust_cday;
    int cust_cmonth;
    int cust_dday;
    int cust_dmonth;
    int cust_cost;
    int cust_required[10];
    int cust_indcost[10];
};int numcust=10;
struct customer cust[10];
//Database of types of repairs available
struct repair{
    int repair_id;
    char repair_name[100];
    int repair_time;
    int repair_cost[3];
};int repno =10;
struct repair repser[10];
void printreh(int n)
{
    int i;
    if(n==0)
        for(i=0;i<103;i++)
        {
            printf("_");
        }
    else
        for(i=0;i<103;i++)
        {
            printf("-");
        }
    printf("\n");
}
//To print bill
void print_bill(char name[30],char no[10],int ccost,int exescount,int extracost,int bill)
{
    float service_tax,rcost;
    int i,lenght,j;
    service_tax=cartax*ccost/100;
    rcost=ccost+service_tax;

    printreh(0);
    if(bill==1)
        printf("                                     ESTIMATED CAR BILL\n");
    else
        printf("                                         CAR BILL\n");
    printreh(1);
    printf("   HSD car services\n");
    printf("   HSD street\n");
    printf("   Vellore 632001\n");
    printf("                                                                              Receipt no :  %d\n",recp);
    printf("                                                                            Customer Name:  %s\n",name);
    printf("                                                                               Vehicle No:  %s\n",no);
    printreh(0);
    printf("   SERVICE DESCRIPTION                                                                      RS AMOUNT\n");
    printreh(1);
    for(i=0;i<10;i++)
    {
        if(repser[required[i]].repair_cost[0]!=-1 && ind_cost[required[i]]!=0)
        {
            lenght=strlen(repser[required[i]].repair_name);
            for(j=0;j<44-lenght;j++)
            {
                strcat(repser[required[i]].repair_name," ");
            }
            printf("   %s                                              %d\n",repser[required[i]].repair_name,ind_cost[required[i]]);
        }
    }
    if(exescount==1)
    {
        printf("   Extra repairs cost                                                                        %d",extracost);
    }
    printf("\n\n\n");
    printreh(1);
    printf("                                                                      AMOUNT                 %d\n",ccost);
    printf("                                                                SERVICE TAX                  %.2f\n",service_tax);
    printreh(1);
    printf("                                                                TOTAL AMOUNT              RS %.2f\n",rcost);
    printreh(1);
    printf("                                         Please come again\n");
    printreh(0);
}

void recprint(int p)
{
    if(p<9)
    {
        printf("id - %d  | service - %s\n",repser[p].repair_id,repser[p].repair_name);
        p++;
        recprint(p);
    }
    else
    {
        printf("id - %d | service - %s\n",repser[p].repair_id,repser[p].repair_name);
    }

}

//For giving car to service
int Car_service()
{
    int i,j,z,x=10,dist,total_time=0,total_cost=0,grade,receipt,jcount,date;
    for(i=0;i<repno;i++)
    {
        if(cust[i].cust_cmonth!=0)
            slno++;
    }

    /*strcpy((repser+0)->repair_name,"Battery replacement------------------------- ");
    strcpy((repser+1)->repair_name,"Brake replacement--------------------------- ");//
    strcpy((repser+2)->repair_name,"Ignition coil and spark plug---------------- ");
    strcpy((repser+3)->repair_name,"Oil filter---------------------------------- ");//
    strcpy((repser+4)->repair_name,"Wiper blade replacement--------------------- ");
    strcpy((repser+5)->repair_name,"New tires ---------------------------------- ");//
    strcpy((repser+6)->repair_name,"Wheel alignment----------------------------- ");//
    strcpy((repser+7)->repair_name,"Wheel balancing----------------------------- ");//
    strcpy((repser+8)->repair_name,"Engine lubrication system replacement------- ");
    strcpy((repser+9)->repair_name,"Scheduled maintenance----------------------- ");

    (repser+0)->repair_time=3;
    (repser+1)->repair_time=6;
    (repser+2)->repair_time=12;
    (repser+3)->repair_time=12;
    (repser+4)->repair_time=3;
    (repser+5)->repair_time=12;
    (repser+6)->repair_time=6;
    (repser+7)->repair_time=3;
    (repser+8)->repair_time=12;
    (repser+9)->repair_time=24;


    (repser+0)->repair_cost[0]=3000;  (repser+0)->repair_cost[1]=2500;  (repser+0)->repair_cost[2]=2000;
    (repser+1)->repair_cost[0]=10000; (repser+1)->repair_cost[1]=9050;  (repser+1)->repair_cost[2]=8000;
    (repser+2)->repair_cost[0]=2200;  (repser+2)->repair_cost[1]=2000;  (repser+2)->repair_cost[2]=1800;
    (repser+3)->repair_cost[0]=836;   (repser+3)->repair_cost[1]=760;   (repser+3)->repair_cost[2]=500;
    (repser+4)->repair_cost[0]=1050;  (repser+4)->repair_cost[1]=950;   (repser+4)->repair_cost[2]=780;
    (repser+5)->repair_cost[0]=26000; (repser+5)->repair_cost[1]=21000; (repser+5)->repair_cost[2]=14000;
    (repser+6)->repair_cost[0]=200;   (repser+6)->repair_cost[1]=0;     (repser+6)->repair_cost[2]=0;
    (repser+7)->repair_cost[0]=250;   (repser+7)->repair_cost[1]=0;     (repser+7)->repair_cost[2]=0;
    (repser+8)->repair_cost[0]=25000; (repser+8)->repair_cost[1]=19000; (repser+8)->repair_cost[2]=15000;
    (repser+9)->repair_cost[0]=2000;  (repser+9)->repair_cost[1]=0;     (repser+9)->repair_cost[2]=0;*/

    for(i=0;i<repno;i++)
    {
        required[i]=-1;
    }
    slno+=2;


    /*FILE *wfile = fopen("repairlist.txt","w+");
    if(wfile==NULL)
    {
        printf("not abel to open file");
        return(1);
    }
    for(i=0;i<repno;i++)
    {
        fprintf(wfile,"%d\t%s\t%d\t%d\t%d\t%d\n",(repser+i)->repair_id,(repser+i)->repair_name,(repser+i)->repair_time,(repser+i)->repair_cost[0],(repser+i)->repair_cost[1],(repser+i)->repair_cost[2]);
    }
    fclose(wfile);*/



    do
    {
        printf("Enter date in the format of MMDD or MDD: ");
        scanf("%d",&date);
        cust[slno].cust_cmonth=date/100;
        cust[slno].cust_cday=date-(100*cust[slno].cust_cmonth);
    }while(cust[slno].cust_cmonth>12 || cust[slno].cust_cmonth<=0 || cust[slno].cust_cday>31 || cust[slno].cust_cday<1);
    printf("Enter your name:");
    scanf(" %[^\n]%*c",cust[slno].cust_name);
    printf("Enter your car number:");
    scanf(" %s",cust[slno].cust_carno);

    printf("Total distance covered by the car (else '0')\n");
    scanf("%d",&z);
    if(z>=0)
    {
        dist=z;
        printf("As your car has traveled an approximate distance of %d KM we recommend you to take this services\n",dist);

        if(z>3000)
        {
            printf("%s\n",repser[6].repair_name);
            if(5000<=dist)
            {
                printf("%s\n",repser[3].repair_name);
                printf("%s\n",repser[7].repair_name);
                if(10000<=dist)
                {
                    printf("%s\n",repser[1].repair_name);
                    if(20000<=dist)
                    {
                        printf("%s\n",repser[5].repair_name);
                    }
                }
            }
        }
        else
        {
            printf("There are no recommended repairs\n");
        }

    }
    printf("\nThese are the services available at our showroom\n\n");

    recprint(0);

    printf("According to the given ID's for each type of service select what services does your car required\n");
    printf("After all required services are given please enter -1\n");

    for(i=0;i<repno;i++)
    {
        jcount=0;
        printf("Enter required repair id\n");
        scanf("%d",&z);
        for(j=0;j<x;j++)
        {
            if(required[j]==z-1)
            {
                jcount=1;
            }
	    }
	    if(jcount==0)
	    {
	        if(z!=-1)
	        {
	            required[i]=z-1;
		    }
		    if(z==-1)
		    {
		        break;
		    }
	    }
	    if(jcount==1)
	    {
	        printf("this is already taken\n");
	        i--;
	    }

    }

    for(i=0;i<repno;i++)
    {
        if(required[i]!=-1)
        {
            if(repser[required[i]].repair_cost[1]!=0)
            {
                do
                {
                    printf("enter which grade quality do you want for %s\n",repser[required[i]].repair_name);
                    printf("There are three grades 1,2,3 select one , 1 is the best grade,0 if you want to cancel\n");
                    scanf("%d",&grade);
                    if(grade==1 || grade==2 || grade ==3)
                    {
                        grade=grade-1;
                        total_cost+=repser[required[i]].repair_cost[grade];
                        ind_cost[required[i]]=repser[required[i]].repair_cost[grade];
                    }
                }while(grade!=0 && grade!=1 && grade!=2);
            }
            else
            {
                total_cost+=repser[required[i]].repair_cost[0];
                ind_cost[required[i]]=repser[required[i]].repair_cost[0];
            }
        }
    }

    for(i=0;i<repno;i++)
    {
        if(required[i]!=-1)
        {
            total_time+=repser[required[i]].repair_time;
        }

    }

    if(total_time%24==0)
    {
        total_time=(total_time/24);
    }
    else
    {
        total_time=(total_time/24)+1;
    }

    if(total_time==1)
    {
        printf("your repairs will be completed in %d day\n",total_time);
    }
    else
    {
        printf("your repairs will be completed by %d days\n",total_time);
    }
    cust[slno].cust_time=total_time;
    cust[slno].cust_cost=total_cost;
    printf("you can pay the bill when you come to take your car\n");
    printf("If you want to print estimated receipt enter 1 else enter 0\n");
    scanf("%d",&receipt);

    if(receipt==1)
    {
        print_bill(cust[slno].cust_name,cust[slno].cust_carno,total_cost,0,0,1);

    }
    if(receipt==0)
    {
        printf("total estimated cost for repair is %d\n",total_cost);
    }

    printf("If there are any extra repairs we will inform you when you come again\n\n\n");

    for(i=0;i<10;i++)
    {
        cust[slno].cust_required[i]=required[i];
        cust[slno].cust_indcost[i]=ind_cost[i];
    }

    return(0);
}
//for taking car after service
int Car_return()
{
    int rcar_time,extra,extrarep,i,tcount=0,j;
    printf("Welcome back\nPlease enter your car no\n");
    char rcar_no[10];
    scanf("%s",rcar_no);
    for(i=0;i<numcust;i++)
    {
        if(strcmp(cust[i].cust_carno,rcar_no)==0 && cust[i].cust_dday==0)
        {
            int date;
            printf("Hi Mr/Ms %s\n",cust[i].cust_name);
            do
            {
                printf("Enter date in the format MMDD or MDD:\n");
                scanf("%d",&date);
                cust[i].cust_dmonth=date/100;
                cust[i].cust_dday=date-(100*cust[i].cust_dmonth);
            }while(cust[i].cust_dmonth<1 || cust[i].cust_dmonth>12 || cust[i].cust_dday<0 || cust[i].cust_dday>31);

            if(cust[i].cust_dmonth-cust[i].cust_cmonth==0)
            {
                rcar_time=cust[i].cust_dday-cust[i].cust_cday;
            }
            else
            {
                rcar_time=30-(cust[i].cust_cday-cust[i].cust_dday);
            }
            if(rcar_time>=cust[i].cust_time)
            {
                for(j=0;j<10;j++)
                {
                    required[j]=cust[i].cust_required[j];
                    ind_cost[j]=cust[i].cust_indcost[j];
                }
                printf("Your work has been completed\n");
                printf("Give 1 if any extra repairs has been done else enter 0\n");
                scanf("%d",&extra);
                if(extra == 1)
                {
                    printf("What is the total cost if extra repairs\n");
                    scanf("%d",&extrarep);
                    cust[i].cust_cost+=extrarep;
                    print_bill(cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost,extra,extrarep,0);
                }
                if(extra == 0)
                {
                    printf("This is the bill\n");
                    print_bill(cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost,0,0,0);
                }

            }
            else
            {
                cust[i].cust_dday=0;cust[i].cust_dmonth=0;
                printf("All your work has not completed\nPlease come after %d day\n\n\n",(cust[i].cust_time - rcar_time));
            }
            tcount=1;
        }
    }

    if(tcount==0)
    {
        printf("A car with car number %s is not with us\n\n\n",rcar_no);
    }

    return 0;

}

void printrecphead(int flag)
{

    printreh(0);
    if(flag==0)
        printf("                                    DELEVERED CARS REPORT\n");
    if(flag==1)
        printf("                                  NOT-DELEVERED CARS REPORT\n");
    printreh(1);
    printf("   Date                Customer Name                    Car Number              Total Cost \n");
    printreh(1);
}

void printreport(int day,int month,char name[30],char carno[10],int cost)
{

    int index1,index2,index3;
    char carnoo[10];char namee[30];
    strcpy(carnoo,carno);strcpy(namee,name);
    index1= strlen(namee);
    index2= strlen(carnoo);
    index1=29-index1;
    index2=9-index2;
    for(index3=0;index3<index1;index3++)
    {
        strcat(namee," ");
    }
    for(index3=0;index3<index2;index3++)
    {
        strcat(carnoo," ");
    }

    printf("   %d-%d               %s    %s               %.2f  \n",day,month,namee,carnoo,cost*(1+cartax/100));
}

void rip1()
{
    int date,day,month,i,dnd,tcount=0;
    printf("Enter 0 for delivered 1 of not delivered list\n");
    scanf("%d",&dnd);
    if(dnd==1)
    {
        do
        {
            printf("Enter date in the format of MMDD or MDD: ");
            scanf("%d",&date);
            month=date/100;
            day=date-(100*month);
        }while(month<1 || month >12 || day<1 || day>31);

        for(i=0;i<numcust;i++)
        {
            if(day==cust[i].cust_cday && month==cust[i].cust_cmonth && cust[i].cust_dday==0)
            {
                if(tcount==0)
                {
                    tcount=1;
                    printrecphead(dnd);
                }
                printreport(cust[i].cust_cday,cust[i].cust_cmonth,cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost);
            }
        }

    }
    if(dnd==0)
    {
        do
        {
            printf("Enter date in the format of MMDD or MDD: ");
            scanf("%d",&date);
            month=date/100;
            day=date-(100*month);
        }while(month<1 || month >12 || day<1 || day>31);

        for(i=0;i<numcust;i++)
        {
            if(day==cust[i].cust_dday && month==cust[i].cust_dmonth)
            {
                if(tcount==0)
                {
                    tcount=1;
                    printrecphead(dnd);
                }
                printreport(cust[i].cust_cday,cust[i].cust_cmonth,cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost);
            }
        }
    }
    if(tcount==0)
    {
        printf("No data available\n\n");
    }
}

void rip2()
{
    int date,day1,day2,month1,month2,i,dnd,tcount=0;
    printf("Enter 0 for delivered 1 of not delivered list\n");
    scanf("%d",&dnd);
    do
    {
        printf("Enter first date in the format of MMDD or MDD: ");
        scanf("%d",&date);
        month1=date/100;
        day1=date-(100*month1);
    }while(month1>12 || month1 <1 || day1>31 || day1<1);
    do
    {
        printf("Enter last date in the format of MMDD or MDD: ");
        scanf("%d",&date);
        month2=date/100;
        day2=date-100*month2;
    }while(month2>12 || month2 <1 || day2>31 || day2<1);
    if(dnd==1)
    {
        for(i=0;i<numcust;i++)
        {
            if(day1<=cust[i].cust_cday && month1<=cust[i].cust_cmonth && day2>=cust[i].cust_cday && month2>=cust[i].cust_cmonth && cust[i].cust_dday==0)
            {
                if(tcount==0)
                {
                    tcount=1;
                    printrecphead(dnd);
                }
                printreport(cust[i].cust_cday,cust[i].cust_cmonth,cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost);
            }
        }
    }
    if(dnd==0)
    {
        for(i=0;i<numcust;i++)
        {
            if(day1<=cust[i].cust_dday && month1<=cust[i].cust_dmonth && day2>=cust[i].cust_dday && month2>=cust[i].cust_dmonth)
            {
                if(tcount==0)
                {
                    tcount=1;
                    printrecphead(dnd);
                }
                printreport(cust[i].cust_cday,cust[i].cust_cmonth,cust[i].cust_name,cust[i].cust_carno,cust[i].cust_cost);
            }
        }
    }
    if(tcount==0)
    {
        printf("No data available\n\n");
    }
}



void reports()
{
    int rip;
    printf("1) Press 1 if you want day wise reports\n2) Press 2 if you want reports between two days\n");
    scanf("%d",&rip);
    switch(rip)
    {
        case 1:
            rip1();
            break;
        case 2:
            rip2();
            break;
    }

}
int Car_services()
{
    int choice,i;



    int kn=0;
    FILE* rfile=fopen("repairlist.txt","r");
    if(rfile==NULL)
    {
        printf("not abel to open file");
        return 2;
    }
    char buffer[200];
    fgets(buffer,200,rfile);
    while(!feof(rfile))
    {
        struct repair *p = repser +kn;
        sscanf(buffer,"%d %d  %d  %d  %d  %s\n",&p->repair_id,&p->repair_time,&p->repair_cost[0],&p->repair_cost[1],&p->repair_cost[2],&p->repair_name);
        fgets(buffer,200,rfile);kn++;
    }





    FILE * custfile=fopen("customer_data.txt","r");
    if(custfile==NULL)
    {
        printf("cant open file\n");
        return (1);
    }
    char buff[200];
    fgets(buff,200,custfile);
    while(!feof(custfile))
    {
        struct customer *p=cust + i;
        sscanf(buff ,"%d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",&p->cust_time,&p->cust_cday,&p->cust_cmonth,&p->cust_dday,&p->cust_dmonth,&p->cust_cost,&p->cust_carno,&p->cust_name,&p->cust_required[0],&p->cust_required[1],&p->cust_required[2],&p->cust_required[3],&p->cust_required[4],&p->cust_required[5],&p->cust_required[6],&p->cust_required[7],&p->cust_required[8],&p->cust_required[9],&p->cust_indcost[0],&p->cust_indcost[1],&p->cust_indcost[2],&p->cust_indcost[3],&p->cust_indcost[4],&p->cust_indcost[5],&p->cust_indcost[6],&p->cust_indcost[7],&p->cust_indcost[8],&p->cust_indcost[9]);
        fgets(buff,200,custfile);
        i++;
    }
    fclose(custfile);

    printf("1) Enter 1 for car service\n2) Enter 2 for car delivery\n3) Enter 3 for reports\n4) Enter 4 to exit from car services\n");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
            Car_service();
            recp++;
            break;
        case 2:
            Car_return();
            break;recp++;
        case 3:
            reports();
            break;
        default:
            break;
        }



    FILE *write=fopen("customer_data.txt","w");
    if(write==NULL)
    {
        printf("error occurred");
        return (1);
    }
    for(i=0;i<10;i++)
    {
        if(cust[i].cust_time==1 || cust[i].cust_time==2 || cust[i].cust_time==3 || cust[i].cust_time==4)
            fprintf(write,"%d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",cust[i].cust_time,cust[i].cust_cday,cust[i].cust_cmonth,cust[i].cust_dday,cust[i].cust_dmonth,cust[i].cust_cost,cust[i].cust_carno,cust[i].cust_name,cust[i].cust_required[0],cust[i].cust_required[1],cust[i].cust_required[2],cust[i].cust_required[3],cust[i].cust_required[4],cust[i].cust_required[5],cust[i].cust_required[6],cust[i].cust_required[7],cust[i].cust_required[8],cust[i].cust_required[9],cust[i].cust_indcost[0],cust[i].cust_indcost[1],cust[i].cust_indcost[2],cust[i].cust_indcost[3],cust[i].cust_indcost[4],cust[i].cust_indcost[5],cust[i].cust_indcost[6],cust[i].cust_indcost[7],cust[i].cust_indcost[8],cust[i].cust_indcost[9]);
    }
    fclose(write);

        return (0);
}
void New_car()
{
    printf("\n");
}

void Job()
{
    printf("\n");
}
int main()
{

    int choice,inf=1;
    while(inf>0)
    {
        printf("1) Press 1 to buy a new car\n2) Press 2 for car services \n3) Press 3 for job opportunity\n4) Press 4 to quit from the application\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            New_car();
            break;
        case 2:
            Car_services();
            break;
        case 3:
            Job();
            break;
        case 4:
            return (0);
        }
        printf("\n\n\n");
    }
}
