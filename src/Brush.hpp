#pragma once
#include <raylib.h>

#define MAX_SIZE 20.0f
#define MIN_SIZE 0.5f


Color COLORS[6]={RED,BLUE,YELLOW,GREEN,WHITE,BLACK};

class Brush{

    public:
    Color color;
    float size ;
    
    Brush(){
        size = 4.0f;
        color = WHITE;
    }
    void changeSize(){
        float wheelMove = GetMouseWheelMove();
        if(wheelMove > 0.0f && size <=MAX_SIZE){
            size += 0.4f;
        }else if (wheelMove < 0.0f && size >= MIN_SIZE){
            size -= 0.4f;
        }else{
            return;
        }

    }
    void changeColor(){
        static int count ;
        count = (count+1)%6;
        color = COLORS[count];
    }


};