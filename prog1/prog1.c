#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int  id;
    char name[50];
    float marks;
}student;

 void displayRecord(int m);

 void deleteRecord(int del_id);

int main(){
    int n;
    student s;
    FILE *fp;
    fp = fopen("Student.dat","wb"); 
    printf("enter the size of record:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("Enter the ID of student %d:",i+1);
        scanf("%d",&s.id);

        printf("Enter the name of student %d:",i+1);
        scanf("%s",s.name);

        printf("Enter the marks of student %d:",i+1);
        scanf("%f",&s.marks);

        fwrite(&s, sizeof(student), 1, fp);
    }
 fclose(fp);
    int m;
  printf("Enter the record number to display:");
  scanf("%d",&m);
  
  displayRecord(m);

  int del_id;
printf("\n Enter the Id to be deleted:\n");
scanf("%d",&del_id);

deleteRecord(del_id);

fp = fopen("Student.dat","rb");
while(fread(&s,sizeof(student),1,fp)){  
    printf("\nID:%d",s.id);
    printf("\nName:%s",s.name);
    printf("\nMarks:%.2f\n",s.marks);
}


fclose(fp);






}

void displayRecord(int m){
     student s;
     FILE *fp;

fp = fopen("Student.dat","rb");

    if (fp==NULL){
        printf("File not found\n");
        return ;


    }
fseek(fp,(m-1)*sizeof(student),SEEK_SET);

fread(&s,sizeof(student),1,fp);

printf("\nRecord %d:",m);
printf("\nID:%d",s.id);
printf("\nName:%s",s.name);
printf("\nMarks:%.2f",s.marks);


fclose(fp);
}

void deleteRecord(int del_id){

    FILE *fp,*temp;
    student s;
     
fp = fopen("student.dat","rb");
temp = fopen("temp.dat","wb");

if(fp==NULL){
    printf("file not found\n");
    return ;
}

while(fread(&s,sizeof(student),1,fp)){

    if(s.id != del_id){
        fwrite(&s,sizeof(student),1,temp);
    }

    fclose(fp);
    fclose(temp);

remove("student.dat");
rename("temp.dat","student.dat");

printf("deleted successfully");
}

}