#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void cycle_data(int n);
void bus_data(int n);
void car_data(int n);
void search();
void cycle();
void bus();
void car();
int menu();
int c_count=0,b_count=0,car_count=0,c_amount=0,b_amount=0,car_amount=0,count=0,amount=0;
int n,num,c_add=0,b_add=0,car_add=0,cycle_array[50],car_array[50],bus_array[40],arr;
void show_data();
void Reset();
int Delete();
int main(){
    while(1){
    switch(menu()){
        case 1:
        cycle();
        break;
        
        case 2:
        bus();
        break;
        
        case 3:
        car();
        break;

        case 4:
        show_data();
        break;

        case 5:
        Reset();
        break;

        case 6:
        exit(0);

        case 7:
        Delete();
        break;

        case 8:
        search();
        break;


        default:
        printf("\nInvalid choice");

    }
}
}
int Delete(){
    printf("\n1.Delete cycle vechicle");
    printf("\n2.Delete bus vechicle");
    printf("\n3.Delete car vechicle\n");
    printf("Enter choice: ");
    scanf("%d",&num);
    if (num==1){
        c_count;
        printf("Enter the number of cycle vechicle to delete: \n");
        scanf("%d",&n);
        if(n>c_count){
            printf("Sorry, Cannot delete");
        }
        else{
            c_count=c_count-n;
            printf("The update vechicle is: %d\n",c_count);
            c_amount=c_amount-(n*20);
            printf("Data deleted successfully\n");
        }
        
    }   
    else if(num==2){
        printf("\nEnter the number of bus vehicle to delete: \n");
        scanf("%d",&n);
        if(n>b_count){
            printf("Sorry, Cannot delete");
        }
        else{
           b_count=b_count-n;
           printf("The update vechicle is: %d\n",b_count);
           printf("Data deleted successfully\n");
           b_amount=b_amount-(n*100);
        }
        
    }
    else if(num==3){
        printf("\nEnter the number of car vehicle to delete: \n");
        scanf("%d",&n);
        if(n>car_count){
            printf("Sorry, Cannot delete");
            
        }
        else{
          car_count=car_count-n;
          printf("The update vechicle is: %d\n",car_count);
          car_amount=car_amount-(n*200);
          printf("Data deleted successfully\n");
        }
        
    }
    else{
        printf("\nInvalid choice");
    }
}
int menu(){
    int ch;
    printf("\nWelcome to the Vehicle Parking Simulator\n");
    printf("\n1.Add Cycle");
    printf("\n2.Add Bus");
    printf("\n3.Add car");
    printf("\n4.Show status");
    printf("\n5.Reset Data");
    printf("\n6.Exit");
    printf("\n7.Delete");
    printf("\n8.search");
    printf("\nEnter Your choice: ");
    scanf("%d",&ch);
    return ch;
}
void show_data(){
    count=c_count+b_count+car_count;
    amount=c_amount+b_amount+car_amount;
    printf("\nNumber of Cycle is: %d",c_count);
    printf("\nNumber of Bus is: %d",b_count);
    printf("\nNumber of car is: %d",car_count);
    printf("\nTotal Number of vehicles is: %d",count);
    printf("\nTotal amount is: %d\n",amount);
}
void Reset(){
    int ch;
    printf("Do u want to Reset data");
    printf("\n1.Yes");
    printf("\n2.No");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        if(ch==1){
            c_count=0;
            b_count=0;
            car_count=0;
            count=0;
            c_amount=0;
            b_amount=0;
            car_amount=0;
            amount=0;
            FILE *f1 = fopen("cycle.txt", "w");
            if (f1) fclose(f1);

            FILE *f2 = fopen("bus.txt", "w");
            if (f2) fclose(f2);

            FILE *f3 = fopen("car.txt", "w");
            if (f3) fclose(f3);

            printf("\nfiles have been reset successfully\n");
        }
        case 2:
        printf("\nReset cancelled.\n");
        break;

        default:
        printf("\nInvalid argument");
        break;
    }
}


void cycle(){
    printf("Enter the Number of Cycles to Add: ");
    scanf("%d",&c_add);
    c_count=c_count+c_add;
    c_amount=c_count*20;
    cycle_data(c_add);
}
void bus(){
    printf("Enter the Number of bus to Add: ");
    scanf("%d",&b_add);
    b_count+=b_add;
    b_amount=b_count*100;
    bus_data(b_add);
}
void car(){
    printf("Enter the Number of cars to Add: ");
    scanf("%d",&car_add);
    car_count+=car_add;
    car_amount=car_count*200;
    car_data(car_add);
}
void cycle_data(int n){
    int cycle_array[n];
    FILE*fptr;
    fptr=fopen("cycle.txt","a");
    for(int i=0;i<n;i++){
        printf("Enter the Token Number of cycle on %d place: ",i+1);
        scanf("%d",&cycle_array[i]);
        fprintf(fptr,"%d\t",cycle_array[i]);
    }
    printf("Entry Successful");
    fclose(fptr);
}
void bus_data(int n){
    bus_array[n];
    FILE*fptr;
    fptr=fopen("bus.txt","a");
    for(int j=0;j<n;j++){
        printf("Enter the Token Number of bus on %d place: ",j+1);
        scanf("%d",&bus_array[j]);
        fprintf(fptr,"%d\t",bus_array[j]);
    }
    printf("Entry Successful");

}
void car_data(int n){
    car_array[n];
    FILE*fptr;
    fptr=fopen("car.txt","a");
    for(int j=0;j<n;j++){
        printf("Enter the Token Number of bus on %d place: ",j+1);
        scanf("%d",&car_array[j]);
        fprintf(fptr,"%d\t",car_array[j]);
    }
    printf("Entry Successful");
}  
void search() {
    printf("\n1.search cycle vehicle\n2.search bus vehicle\n3.search car vehicle\n");
    printf("Enter choice: ");
    scanf("%d", &num);

    char *filename;
    if (num == 1) filename = "cycle.txt";
    else if (num == 2) filename = "bus.txt";
    else if (num == 3) filename = "car.txt";
    else {
        printf("\nInvalid choice");
        return;
    }

    printf("Enter the Token to Find: ");
    scanf("%d", &n);

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("File doesn't exist or no records yet.\n");
        return;
    }

    int temp_num;
    int flag = 0;
    while (fscanf(fptr, "%d", &temp_num) == 1) {
        if (temp_num == n) { 
            flag = 1;
            break;
        }
    }
    fclose(fptr);

    if (flag == 1) printf("Token Found!\n");
    else printf("Token Not Found.\n");
}


