#include <stdio.h>
#include <string.h>

struct employee{
    char    name[32];
    int     id;
    float   salary;
};

int main()
{
    struct employee temp[8];     
    int i=0;
    for(;i<8;i++){
        printf("input employee name:\n");
        scanf("%s",&(temp[i].name));
        printf("input id number:\n");
        scanf("%d",&(temp[i].id));
        printf("input salary:\n");
        scanf("%f",&(temp[i].salary));
    }
    printf("please input a employee id num and search for the employee:");
    int employee_id = 0,finded = 0;
    scanf("%d",&employee_id);
    for(i=0;i<8;i++){
        if(temp[i].id == employee_id){
            printf("finded! the employee's name:%s,salary is:%f\n",temp[i].name,temp[i].salary);
            finded = 1;
        }
    }
    if(!finded){
        printf("the employee_id not finded!\n");
    }
    return 0;
}
