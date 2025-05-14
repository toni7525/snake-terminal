#include <iostream>
#include <windows.h>
#include <cstdlib>
void Show();
using namespace std;
struct vector2{
int x,y;
};
int renderx = 10,rendery = 10,snakesize = 3,fps,x,y;
float inputx,inputy;
vector2 snakepos[99];
vector2 fruit;
string snakeform = "[]";
void deathanim(){
inputx = 0;
inputx = 0;
snakeform = "##";
for(int i = snakesize;i>=0;i--){
    snakesize--;
    Show();
    Sleep(1500/snakesize);
    system("cls");
    system("title skill issue");
}
}

void colisons(){
  if(snakepos[0].x < 0||
     snakepos[0].y < 0 ||
     snakepos[0].x > renderx||
     snakepos[0].y > rendery ){
     deathanim();
     }
}

void randomfruit(){
fruit.x = rand() % renderx;
fruit.y = rand() % rendery;
}

void checkforpos(){
bool found = false;
for(int j = 0;j<=snakesize;j++){
 if(snakepos[j].x == x
    && snakepos[j].y == y){
    cout<<snakeform;
    found = true;
 }
}
if(fruit.x == x&& fruit.y == y){
    cout<<"@*";
    found = true;
}
if(!found){
cout<<"  ";
}
}

void lines(int nr){
    for(int j = nr;j>=0;j--){
        cout<<"__";
    }
}

void Show(){
x = 0;
y = 0;
lines(renderx/2-2);
cout<<"scor:"<<snakesize;
lines(renderx/2-1);
cout<<endl;
for(y;y<=rendery;y++){
    for(x;x<=renderx;x++){
     checkforpos();
    }
x = 0;
cout<<endl;
}
lines(renderx);
cout<<endl;
}
bool increasesize =false;
void Calculatebody(){
if(increasesize){
snakesize++;
increasesize = false;
}
for(int k = snakesize;k>0;k--){
snakepos[k] = snakepos[(k-1)];
}
snakepos[0].x = snakepos[0].x + inputx;
snakepos[0].y = snakepos[0].y + inputy;
if(snakepos[0].x == fruit.x && snakepos[0].y == fruit.y){
  increasesize = true;
  randomfruit();
}
}

void Input(){
//inputy = 0;
//inputy = 0;
if(GetKeyState(VK_UP) & 0x8000){
inputy = -1;
inputx = 0;
}
if(GetKeyState(VK_DOWN) & 0x8000){
inputy = 1;
inputx = 0;
}
if(GetKeyState(VK_LEFT) & 0x8000){
inputx = -1;
inputy = 0;
}
if(GetKeyState(VK_RIGHT) & 0x8000){
inputx = 1;
inputy = 0;
}
}

int main()
{
    randomfruit();
    fps = 5;
    float waittime =1000/fps;
    while(true){
    Input();
    colisons();
    Calculatebody();
    Show();
    Sleep(waittime);
    system("cls");
    }
    return 0;
}
