#include <stdio.h>

struct point{

int x;

int y;
};

void print (struct point p) {
    printf("%d %d \n", p.x, p.y);
}
int main(){ 

struct point pl = {223,323};

struct point p2 = {56,653};

print (pl);

print (p2);

return 0;

}