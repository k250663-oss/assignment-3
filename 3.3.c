#include<stdio.h>
#include<string.h>
struct employee{
    int id;
    char name[50];
    char designation[50];
    int salary ;
};
void highest_pay(struct employee e[] , int n){
    int highest = 0;
    int m;
        for(int i =0 ; i<n-1 ; i++){
            if(e[i].salary>e[m].salary){
               m = i;
            }
        }
        printf("\nthe highest pay is:%d of %s\n" , e[m].salary , e[m].name );
    } 
void search(struct employee e[] , int n){
    char search[50];
    printf("\n\nenter name of employee you want to search:\n");
    scanf("%s" , search);
    for(int i =0 ; i<n ; i++){
        if(strcmp(e[i].name , search)==0){
            printf("id:%d name:%s designation:%s salary:%d" ,e[i].id , e[i].name , e[i].designation ,e[i].salary );
        }
    }
    int s;
    printf("\n\nid of the employee you want to search:\n");
    scanf("%d" , &s);
    for(int i = 0; i<n ; i++){
        if(e[i].id == s){
            printf("id:%d name:%s designation:%s salary:%d" ,e[i].id , e[i].name , e[i].designation ,e[i].salary );
        }
    }
}
void display(struct employee e[] , int n){
    printf("\n\n========TABLE OF EMPLOYES========\n");
    printf("id\tname\tdesignation\tsalary\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t%s\t%s\t%d\n" , e[i].id , e[i].name , 
        e[i].designation , e[i].salary);
    }
}
int main(){
    int id , salary;
    struct employee e[4];
   char name[50];
    char designation[50];
    int n=4;     //4 employees
    for(int i =0 ; i<n ; i++){
        printf("enter id ,name , designation , salary of employee%d:\n" , i+1);
        scanf("%d %s %s %d" , &e[i].id , &e[i].name , &e[i].designation ,&e[i].salary);
    }
    display(e , n);
    highest_pay(e , n);
    search(e , n);
}