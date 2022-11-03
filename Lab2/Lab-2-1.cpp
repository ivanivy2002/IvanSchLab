#include<iostream>
#include<math.h>
using namespace std;
#define A 20
int initialize();
int integerize(float);
int quit_ask();
class SegmentS_Bool{
    public:
        bool mat[A][A]={false};
        struct Point{
            int x;
            int y;
        }sta_p,end_p; 
        
        void input();
        void line(int,int,int,int);    
        void draw();
        void printResult();
        void zeroize();
}segment_b;

class SegmentS_Char{
    public:
        char mat[A][A]={'\0'};
        struct Point{
            int x;
            int y;
        }sta_p,end_p; 
        
        void input();
        void line(int,int,int,int);    
        void draw();
        void printResult();
        void zeroize();       
}segment_c;

int initialize(){
    int flag_scale;
    cout<<"Choose the Scale to Display, "<<endl;
    cout<<"Bit Scale (0) or 256 Gray Scale (1) : "<<endl;
    cin>>flag_scale;
    return flag_scale;  
}

int integerize(float x){
    return (x>0.0) ? floor(x+0.5) : ceil(x-0.5);
}

int quit_ask(){
    int ask;
    cout<<"Quit (0) or Continue the Test (1): "<<endl;
    cin>>ask;
    return ask;
}

void SegmentS_Char::input(){
    cin>>sta_p.x;
    cin>>sta_p.y;
    cin>>end_p.x;
    cin>>end_p.y;
}

void SegmentS_Char::line(int x1,int y1,int x2,int y2){
    sta_p.x=x1;
    sta_p.y=y1;
    end_p.x=x2;
    end_p.y=y2;
    draw();
} 

void SegmentS_Char::draw(){
    if(sta_p.x>end_p.x){
        sta_p.x=sta_p.x+end_p.x;end_p.x=sta_p.x-end_p.x;sta_p.x=sta_p.x-end_p.x;
        sta_p.y=sta_p.y+end_p.y;end_p.y=sta_p.y-end_p.y;sta_p.y=sta_p.y-end_p.y;
    }
    mat[end_p.x][end_p.y]=mat[sta_p.x][sta_p.y]='1';  
    float dx=(float)(end_p.x-sta_p.x);
    float dy=(float)(end_p.y-sta_p.y);
    if(dx!=0){
        float k=dy/dx;
        if(k<=1&&k>=-1){
            for(int xx=0;xx<A;xx++){
                int yy=integerize(((float)(xx-sta_p.x))*k+(float)sta_p.y);
                if(yy>=0 && yy<A) mat[xx][yy]='1';
            }  
        }
        else{
            float p=1/k;
            for(int yy=0;yy<A;yy++){
                int xx=integerize(((float)(yy-sta_p.y))*p+(float)sta_p.x);
                if(xx>=0 && xx<A) mat[xx][yy]='1';
            } 
        }
    }
    else for(int h=0;h<A;h++) mat[sta_p.x][h]='1'; 
}

void SegmentS_Char::printResult(){
    for(int j=A-1;j>=0;j--){
       for(int i=0;i<A;i++) cout<<mat[i][j]<<" ";       
       cout<<endl;
    }
    cout<<endl;
}

void SegmentS_Char::zeroize(){
    for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) mat[i][j]='0';
}


void SegmentS_Bool::input(){
    cin>>sta_p.x;
    cin>>sta_p.y;
    cin>>end_p.x;
    cin>>end_p.y;
}

void SegmentS_Bool::line(int x1,int y1,int x2,int y2){
    sta_p.x=x1;
    sta_p.y=y1;
    end_p.x=x2;
    end_p.y=y2;
    draw();
} 

void SegmentS_Bool::draw(){
    if(sta_p.x>end_p.x){
        sta_p.x=sta_p.x+end_p.x;end_p.x=sta_p.x-end_p.x;sta_p.x=sta_p.x-end_p.x;
        sta_p.y=sta_p.y+end_p.y;end_p.y=sta_p.y-end_p.y;sta_p.y=sta_p.y-end_p.y;
    }
    mat[end_p.x][end_p.y]=mat[sta_p.x][sta_p.y]=true;  
    float dx=(float)(end_p.x-sta_p.x);
    float dy=(float)(end_p.y-sta_p.y);
    if(dx!=0){
        float k=dy/dx;
        if(k<=1&&k>=-1){
            for(int xx=0;xx<A;xx++){
                int yy=integerize(((float)(xx-sta_p.x))*k+(float)sta_p.y);
                if(yy>=0 && yy<A) mat[xx][yy]=true;
            }  
        }
        else{
            float p=1/k;
            for(int yy=0;yy<A;yy++){
                int xx=integerize(((float)(yy-sta_p.y))*p+(float)sta_p.x);
                if(xx>=0 && xx<A) mat[xx][yy]=true;
            } 
        }
    }
    else for(int h=0;h<A;h++) mat[sta_p.x][h]=true; 
}

void SegmentS_Bool::printResult(){
    for(int j=A-1;j>=0;j--){
       for(int i=0;i<A;i++) cout<<mat[i][j]<<" ";       
       cout<<endl;
    }
    cout<<endl;
}

void SegmentS_Bool::zeroize(){
    for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) mat[i][j]=false;
}

int main(int argc, char const *argv[]){
    int end_flag=0;
    while(!end_flag){
        if(initialize()){
            segment_c.zeroize();
            //1. 没有绘制任何线的时候的printResult结果
            segment_c.printResult();
            //2. 绘制第⼀条线后printResult结果
            segment_c.line(2, 0, 2, 19);
            segment_c.printResult();
            //3. 绘制第⼆条线后printResult结果
            segment_c.line(0, 2, 19, 2);
            segment_c.printResult();
            //4. 绘制第三条线后printResult结果
            segment_c.line(19, 19, 0, 0);
            segment_c.printResult();
            //5. 绘制第四条线后printResult结果
            segment_c.line(0, 3, 18, 9);
            segment_c.printResult();
            //6. 绘制第五条线后printResult结果
            segment_c.line(0, 15, 5, 0);
            segment_c.printResult(); 
        }else{
            segment_b.zeroize();
            //1. 没有绘制任何线的时候的printResult结果
            segment_b.printResult();
            //2. 绘制第⼀条线后printResult结果
            segment_b.line(2, 0, 2, 19);
            segment_b.printResult();
            //3. 绘制第⼆条线后printResult结果
            segment_b.line(0, 2, 19, 2);
            segment_b.printResult();
            //4. 绘制第三条线后printResult结果
            segment_b.line(19, 19, 0, 0);
            segment_b.printResult();
            //5. 绘制第四条线后printResult结果
            segment_b.line(0, 3, 18, 9);
            segment_b.printResult();
            //6. 绘制第五条线后printResult结果
            segment_b.line(0, 15, 5, 0);
            segment_b.printResult(); 
        }
        end_flag=1-quit_ask();
    }
    
}
