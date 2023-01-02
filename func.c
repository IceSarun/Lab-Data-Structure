#include <stdio.h>

void inputData(float *w,float *l){
    printf("Enter width : ");
    scanf("%f",w);
    printf("Enter length : ");
    scanf("%f",l);
}
void areaSpace(float *w,float *l,float *a){
    *a=(*w)*(*l);
}
void showArea(float a){
    printf("Rectangle area is %.2f",a);
}

int main(){
    float width, length , area;
    inputData(&width,&length);
    areaSpace(&width,&length,&area);
    showArea(area);
}
