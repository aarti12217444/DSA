#include<stdio.h>
struct student{
    char name[20];
    int age;
    int roll;
    float marks;
};
void print(char name[], int age, int roll, float marks){
    printf("%s %d %d %.2f\n",name,age,roll,marks);
}
int main(){
    struct student s1 = {"Nick",16,56,89.78};
    print(s1.name,s1.age,s1.roll,s1.marks);
    return 0;
}