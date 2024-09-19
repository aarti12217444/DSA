#include <stdio.h>

struct point{

int x;

int y;

};

void print (struct point *ptr) {

printf("%d %d \n", ptr->x, ptr->y);

}

int main(){

struct point p1 ={223,323};

struct point p2={256,653};

print (&p1);

print(&p2);

return 0;
}