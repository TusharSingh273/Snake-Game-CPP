#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

bool game_over=false;
int score=0;
int board_length=10;
vector<vector<int>> snake{{4,4}};
long long food_x=0;
long long food_y=0;
int last_x=0;
int last_y=0;

void display(){
    system("cls");
    cout<<"+";
    for(int i=0;i<10;i++){
        cout<<"-+";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<"|";
            bool b=false;
            for(int k=1;k<=score;k++){
                if(snake[k][0]==i && snake[k][1]==j){
                    b=true;
                }
            }
            if(b){
                cout<<"#";
            }
            else if(snake[0][0]==i && snake[0][1]==j){
                cout<<"S";
            }
            else if(food_x==i && food_y==j){
                cout<<"*";
            }
            
            else{
                cout<<" ";
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"+";
    for(int i=0;i<10;i++){
        cout<<"-+";
    }
    return;
}

void check(){
    if(snake[0][0]<0 || snake[0][1]<0 || snake[0][0]>9 || snake[0][1]>9){
        game_over=true;
        return;
    }
    for(int i=1;i<snake.size();i++){
        if(snake[i][0]==snake[0][0] && snake[i][1]==snake[0][1]){
            game_over=true;
            return;
        }
    }
    return;
}

void update_snake(){
    last_x=snake[score][0];
    last_y=snake[score][1];
    for(int i=score;i>0;i--){
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
}

void generate_food(){
    bool ok=false;
    while(!ok){
        ok=true;
        food_x=rand()%10;
        food_y=rand()%10;
        for(int i=0;i<score+1;i++){
            if(snake[i][0]==food_x && snake[i][1]==food_y){
                ok=false;
                break;
            }
        }
    }
    return;
}

int main() {
    char move;
    char ch;
    cout<<"Welcome to the snake Game\nReady?(y/n) : ";
    cin>>ch;
    if(ch!='y') return 0;
    display();
    generate_food();
    while(!game_over){
        if(_kbhit()){
            move=_getch();
        }
        update_snake();
        if(move=='d'){ snake[0][1]++;}
        else if(move=='a'){ snake[0][1]--;}
        else if(move=='w'){ snake[0][0]--;}
        else if(move=='s'){ snake[0][0]++;}
        if(snake[0][0]==food_x && snake[0][1]==food_y){
            score++;
            snake.push_back({last_x,last_y});
            generate_food();
        }
        check();
        display();
        Sleep(200);
    }
    cout<<"\nSCORE : "<<score;
    return 0;
}