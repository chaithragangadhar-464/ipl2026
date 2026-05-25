#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int  carnum;
    char car_name[50];
    float price;
}car;

void writefile(car c[],int n);
int createpositions(long position[]);
void displayRecord(long position);

int main(){
    int n;
    printf("Enter the number of records:");
    scanf("%d", &n);
    car c[n];
        for (int i=0;i<n;i++){
            printf("\nEnter the cae number:");
            scanf("%d",&c[i].carnum);
            printf("\nEnter the name of car %d:",i+1);
            scanf("%s",c[i].car_name);
            printf("\nEnter the price of car %d:",i+1);
            scanf("%f",&c[i].price); 
        }
long pos[n];
            writefile(c,n);
            int total = createpositions(pos);


for (int i = 0; i < total; i++) {
        printf("Record %d starts at position %ld\n",i + 1, pos[i]);
    }

    int choice;

    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= total) {
        displayRecord(pos[choice - 1]);
    }
    else {
        printf("Invalid record number!\n");
    }

    return 0;
}

        


void writefile(car c[],int n){
    FILE *fp;
    fp = fopen("car.txt","w");

    if(fp == NULL){
        printf("File nor created.");
        return ;
    }

    for(int i=0;i<n;i++){

        fprintf(fp,"%d %s %.2f\n",c[i].carnum,c[i].car_name,c[i].price);

    }
    fclose(fp);
}


int createpositions(long pos[]) {
    FILE *fp = fopen("car.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;
    char line[100];

    while (1) {
        pos[count] = ftell(fp);

        if (fgets(line, sizeof(line), fp) == NULL)
            break;

        count++;
    }

    fclose(fp);
    return count;
}

void displayRecord(long position) {

    FILE *fp = fopen("car.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened!\n");
        return;
    }

    car c;

    // Move file pointer to required position
    fseek(fp, position, SEEK_SET);

    // Read record
    fscanf(fp, "%d %s %f",
           &c.carnum,
           c.car_name,
           &c.price);

    printf("\nRecord Details\n");
    printf("Roll Number : %d\n", c.carnum);
    printf("Name        : %s\n", c.car_name);
    printf("Marks       : %.2f\n", c.price);

    fclose(fp);
}