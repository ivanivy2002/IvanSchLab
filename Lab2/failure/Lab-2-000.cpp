#include<iostream>
#include<math.h>
using namespace std;
#define A 20

int integerize(float);
int quit_ask();
struct MATS_Char{
    char mat[A][A]={'\0'};
};
struct MATS_Bool{
    bool mat[A][A]={false};
};
class SegmentS{
    public:
        int flag_scale;     //private?
        void *p; 
        struct Point{
            int x;
            int y;
        }sta_p,end_p; 
        void initialize();
        void input();
        void line(int,int,int,int);
        void printResult();
}segment;

void SegmentS::initialize(){  
    cout<<"Choose the Scale to Display, "<<endl;
    cout<<"Bit Scale (0) or 256 Gray Scale (1) : "<<endl;
    cin>>flag_scale;
    if(flag_scale){
        //mat=new char[A][A];
        MATS_Char* mat_char = static_cast<MATS_Char*>p;  
        // for(int i = 0;i < A; i++)   
        // *((char*)mat)[i] = new char[A]; 
        for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) p->mat[i][j]='0';
    }else{
        //mat=new bool[A][A];
        MATS_Bool* mat_bool = (MATS_Bool*) p;
            
        // for(int i = 0;i < A; i++)   
        // *((char*)mat)[i] = new bool[A];
        for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) *((bool*)mat)[i][j]=false;
    }  
}

int integerize(float x){
    return (x>0.0) ? floor(x+0.5) : ceil(x-0.5);
}

int quit_ask(){
    int ask;
    delete mat;
    cout<<"Quit (0) or Continue the Test (1): "<<endl;
    cin>>ask;
    return ask;
}

void SegmentS::input(){
    cin>>sta_p.x;
    cin>>sta_p.y;
    cin>>end_p.x;
    cin>>end_p.y;
}


void SegmentS::line(int x1,int y1,int x2,int y2){
    sta_p.x=x1;
    sta_p.y=y1;
    end_p.x=x2;
    end_p.y=y2;
    if(sta_p.x>end_p.x){
        sta_p.x=sta_p.x+end_p.x;end_p.x=sta_p.x-end_p.x;sta_p.x=sta_p.x-end_p.x;
        sta_p.y=sta_p.y+end_p.y;end_p.y=sta_p.y-end_p.y;sta_p.y=sta_p.y-end_p.y;
    }
    //*((char*)mat)[end_p.x][end_p.y]=*((char*)mat)[sta_p.x][sta_p.y]='1';  
    float dx=(float)(end_p.x-sta_p.x);
    float dy=(float)(end_p.y-sta_p.y);
    if(flag_scale){
        if(dx!=0){
            float k=dy/dx;
            if(k<=1&&k>=-1){
                for(int xx=0;xx<A;xx++){
                    int yy=integerize(((float)(xx-sta_p.x))*k+(float)sta_p.y);
                    if(yy>=0 && yy<A) *((char*)mat)[xx][yy]='1';
                }  
            }
            else{
                float p=1/k;
                for(int yy=0;yy<A;yy++){
                    int xx=integerize(((float)(yy-sta_p.y))*p+(float)sta_p.x);
                    if(xx>=0 && xx<A) *((char*)mat)[xx][yy]='1';
                } 
            }
        }
        else for(int h=0;h<A;h++) *((char*)mat)[sta_p.x][h]='1';
    }else{
        if(dx!=0){
            float k=dy/dx;
            if(k<=1&&k>=-1){
                for(int xx=0;xx<A;xx++){
                    int yy=integerize(((float)(xx-sta_p.x))*k+(float)sta_p.y);
                    if(yy>=0 && yy<A) *((bool*)mat)[xx][yy]=true;
                }  
            }
            else{
                float p=1/k;
                for(int yy=0;yy<A;yy++){
                    int xx=integerize(((float)(yy-sta_p.y))*p+(float)sta_p.x);
                    if(xx>=0 && xx<A) *((bool*)mat)[xx][yy]=true;
                } 
            }
        }
        else for(int h=0;h<A;h++) *((bool*)mat)[sta_p.x][h]=true;           
    }
}

void SegmentS::printResult(){
    if(flag_scale){
       for(int j=A-1;j>=0;j--){
            for(int i=0;i<A;i++) cout<<*((char*)mat)[i][j]<<" ";       
            cout<<endl;
       } 
    }else{
        for(int j=A-1;j>=0;j--){
            for(int i=0;i<A;i++) cout<<*((bool*)mat)[i][j]<<" ";       
            cout<<endl;
       } 
    }
    
    cout<<endl;
}

int main(int argc, char const *argv[]){
    do{
            segment.initialize();
            //1. 没有绘制任何线的时候的printResult结果
            segment.printResult();
            //2. 绘制第⼀条线后printResult结果
            segment.line(2, 0, 2, 19);
            segment.printResult();
            //3. 绘制第⼆条线后printResult结果
            segment.line(0, 2, 19, 2);
            segment.printResult();
            //4. 绘制第三条线后printResult结果
            segment.line(19, 19, 0, 0);
            segment.printResult();
            //5. 绘制第四条线后printResult结果
            segment.line(0, 3, 18, 9);
            segment.printResult();
            //6. 绘制第五条线后printResult结果
            segment.line(0, 15, 5, 0);
            segment.printResult();
    }while(quit_ask());
    
}
