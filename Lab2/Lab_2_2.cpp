#include<iostream>
#include<math.h>
using namespace std;
#define A 20
bool initialize();
int integerize(float);
int quit_ask();

template <typename T>
class SegmentS{
    private:
        T white;
        T black;
        T mat[A][A];
        
    public:
        bool flag_scale;
        SegmentS(){
            if(flag_scale){
                white='0';
                black='1';
            }else{
                white=false;
                black=true;
            }
            for(int j=A-1;j>=0;j--) for(int i=0;i<A;i++) mat[i][j]=white; 
        }
        struct Point{
            int x;
            int y;
        }sta_p,end_p; 

        void input();
        void line(int,int,int,int);
        void printResult();
};

bool initialize(){
    bool symbo;
    cout<<"Choose the Scale to Display, "<<endl;
    cout<<"Bit Scale (0) or 256 Gray Scale (1) : "<<endl;
    cin>>symbo;
    return symbo;
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
template <typename T>
void SegmentS<T>::input(){
    cin>>sta_p.x;
    cin>>sta_p.y;
    cin>>end_p.x;
    cin>>end_p.y;
}
template <typename T>
void SegmentS<T>::line(int x1,int y1,int x2,int y2){
    sta_p.x=x1;
    sta_p.y=y1;
    end_p.x=x2;
    end_p.y=y2;
    if(sta_p.x>end_p.x){
        sta_p.x=sta_p.x+end_p.x;end_p.x=sta_p.x-end_p.x;sta_p.x=sta_p.x-end_p.x;
        sta_p.y=sta_p.y+end_p.y;end_p.y=sta_p.y-end_p.y;sta_p.y=sta_p.y-end_p.y;
    }
    //mat[end_p.x][end_p.y]=mat[sta_p.x][sta_p.y]='1';  
    float dx=(float)(end_p.x-sta_p.x);
    float dy=(float)(end_p.y-sta_p.y);
    if(dx!=0){
        float k=dy/dx;
        if(k<=1&&k>=-1){
            for(int xx=0;xx<A;xx++){
                int yy=integerize(((float)(xx-sta_p.x))*k+(float)sta_p.y);
                if(yy>=0 && yy<A) mat[xx][yy]=black;
            }  
        }
        else{
            float p=1/k;
            for(int yy=0;yy<A;yy++){
                int xx=integerize(((float)(yy-sta_p.y))*p+(float)sta_p.x);
                if(xx>=0 && xx<A) mat[xx][yy]=black;
            } 
        }
    }
    else for(int h=0;h<A;h++) mat[sta_p.x][h]=black;
}
template <typename T>
void SegmentS<T>::printResult(){

    for(int j=A-1;j>=0;j--){
        for(int i=0;i<A;i++) cout<<mat[i][j]<<" ";       
        cout<<endl;
    }  
    cout<<endl;
}

int main(int argc, char const *argv[]){
    bool sym_ini;
    do{            
            if(sym_ini=initialize()){
                SegmentS<char> segment;
                segment.flag_scale=sym_ini;
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
            }else{
                SegmentS<bool> segment;  
            
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
            }
    }while(quit_ask());
    
}
