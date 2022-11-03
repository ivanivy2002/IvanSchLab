#include<iostream>
#include<math.h>
using namespace std;
#define A 20
void zeroize();
void line(int x1, int y1, int x2, int y2);//
void printResult();
int integerize(float x);
char mat[A][A]={'\0'};
int main(int argc, char const *argv[]){
    zeroize();
    //1. 没有绘制任何线的时候的printResult结果
    printResult();
    //2. 绘制第⼀条线后printResult结果
    //line(2, 0, 2, 19);
    printResult();
    //3. 绘制第⼆条线后printResult结果
    //line(0, 2, 19, 2);
    printResult();
    //4. 绘制第三条线后printResult结果
    //line(19, 19, 0, 0);
    printResult();
    //5. 绘制第四条线后printResult结果
    line(0, 3, 18, 9);
    printResult();
    //6. 绘制第五条线后printResult结果
    //line(0, 15, 5, 0);
    printResult();
}
void line(int x1, int y1, int x2, int y2){
    if(x1>x2){
        x1=x1+x2;x2=x1-x2;x1=x1-x2;
        y1=y1+y2;y2=y1-y2;y1=y1-y2;
    }
    mat[x2][y2]=mat[x1][y1]='1';
    int x,y;
    float dx=(float)(x2-x1);
    float dy=(float)(y2-y1);
    if(dx!=0){
        float k=dy/dx;
        if(k<=1&&k>=-1){
            for(x=0;x<A;x++){
                y=integerize(((float)(x-x1))*k+(float)y1);
                if(y>=0 && y<A) mat[x][y]='1';
            }  
        }
        else{
            float p=1/k;
            for(y=0;y<A;y++){
                x=integerize(((float)(y-y1))*p+(float)x1);
                if(x>=0 && x<A) mat[x][y]='1';
            } 
        }
    }
    else for(int h=0;h<A;h++) mat[x1][h]='1'; 
}
void printResult(){
    for(int j=A-1;j>=0;j--){
       for(int i=0;i<A;i++) cout<<mat[i][j]<<" ";       
       cout<<endl;
    }
    cout<<endl;
}
void zeroize(){
    for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) mat[i][j]='0';
}
int integerize(float x){
    return (x>0.0) ? floor(x+0.5) : ceil(x-0.5);
}