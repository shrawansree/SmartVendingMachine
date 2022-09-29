#ifndef LCD_H
#define LCD_H

#include "../mbed.h"
#include "N5110.h"

#define DRINK_H 10
#define DRINK_W 7

#define ICON_H 10
#define ICON_W 12


class Display : public N5110{


private:


    //display screen
    int base[HEIGHT][WIDTH];

    int home_selected;
    int hot_selected;
    int cold_selected;
    int drink_selected;
    //sets current screen base : 0 : home, 1 : hot, 2 : cold
    int current_base;

    //set borders
    int row_border;
    int col_border;

    //drinks sprite
    const int drink[DRINK_H][DRINK_W] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0},
        {0,1,1,1,1,1,0},
        {0,1,1,1,1,1,0},
        {0,1,0,0,0,1,0},
        {0,1,0,0,0,1,0},
        {0,1,0,0,0,1,0},
        {0,1,1,1,1,1,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
    //drinks selected sprite
    const int sel_drink[DRINK_H][DRINK_W] = {
        {1,1,1,1,1,1,1},
        {1,1,0,0,0,1,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1}

    };

    //border : home : V : 10
    //border : V : 40
    //home icon sprite
    const int home[ICON_H][ICON_W] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,1,1,1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0,0,1,0,0,0},
        {0,0,0,1,0,1,1,0,1,0,0,0},
        {0,0,0,1,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}   };
        //home selected icon sprite
        const int sel_home[ICON_H][ICON_W] = {
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,0,0,1,1,1,1,1},
        {1,1,1,1,0,0,0,0,1,1,1,1},
        {1,1,1,0,1,1,1,1,0,1,1,1},
        {1,1,0,0,0,0,0,0,0,0,1,1},
        {1,1,1,0,0,0,0,0,0,1,1,1},
        {1,1,1,0,1,1,1,1,0,1,1,1},
        {1,1,1,0,1,0,0,1,0,1,1,1},
        {1,1,1,0,0,0,0,0,0,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };

    //hot icon sprite
    const int hot[ICON_H][ICON_W] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,1,0,0,0,0,0},
        {0,1,0,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,0,0,0,0},
        {0,0,1,0,0,0,0,1,1,1,0,0},
        {0,0,1,0,0,0,0,1,1,1,0,0},
        {0,0,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };

    //hot selected icon sprite
    const int sel_hot[ICON_H][ICON_W] = {
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,1,0,1,1,1,1,1,1},
        {1,1,0,1,0,1,0,1,1,1,1,1},
        {1,0,1,0,1,0,1,1,1,1,1,1},
        {1,1,0,1,0,1,0,1,1,1,1,1},
        {1,1,0,0,0,0,0,0,1,1,1,1},
        {1,1,0,1,1,1,1,0,0,0,1,1},
        {1,1,0,1,1,1,1,0,0,0,1,1},
        {1,1,0,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };

    //cold icon sprite
    const int cold[ICON_H][ICON_W] = {
        {0,0,0,1,0,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,1,0,0},
        {0,1,0,1,0,1,1,0,1,0,1,0},
        {0,0,0,0,1,0,0,1,0,0,0,0},
        {0,0,0,1,0,1,1,0,1,0,0,0},
        {0,0,0,1,0,1,1,0,1,0,0,0},
        {0,0,0,0,1,0,0,1,0,0,0,0},
        {0,1,0,1,0,1,1,0,1,0,1,0},
        {0,0,1,0,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,0,1,0,0,0}
    };

    //cold selected icon sprite
    const int sel_cold[ICON_H][ICON_W] = {
        {1,1,1,0,1,1,1,1,0,1,1,1},
        {1,1,0,1,1,1,1,1,1,0,1,1},
        {1,0,1,0,1,0,0,1,0,1,0,1},
        {1,1,1,1,0,1,1,0,1,1,1,1},
        {1,1,1,0,1,0,0,1,0,1,1,1},
        {1,1,1,0,1,0,0,1,0,1,1,1},
        {1,1,1,1,0,1,1,0,1,1,1,1},
        {1,0,1,0,1,0,0,1,0,1,0,1},
        {1,1,0,1,1,1,1,1,1,0,1,1},
        {1,1,1,0,1,1,1,1,0,1,1,1}
    };

//**********************************************************************************
public:

    //card reader function
    //  lcd(IO, Ser_TX, Ser_RX, MOSI, SCLK, PWM)  
    // Display(PinName io, PinName ser_tx, PinName ser_rx, PinName mosi,
    //             PinName sclk, PinName pwm);
    using N5110 :: N5110;
//functions
//**********************************************************************************
//getter functions
    int get_home(){
        return this->home_selected;
    }

    int get_hot(){
        return this->hot_selected;
    }

    int get_cold(){
        return this->cold_selected;
    }

    int get_drink(){
        return this->drink_selected;
    }

    int get_base(){
        return this->current_base;
    }

    int get_border_r(){
        return this->row_border;
    }

    int get_border_c(){
        return this->col_border;
    }
//setter functions
    void set_home(int value){
        this->home_selected = value;
    }

    void set_hot(int value){
        this->hot_selected = value;
    }

    void set_cold(int value){
        this->cold_selected = value;
    }

    void set_drink(int value){
        this->drink_selected = value;
    }

    void set_base(int value){
        this->current_base = value;
    }
//**********************************************************************************
    void reset_values(){
        this->home_selected = 0;
        this->hot_selected = 0;
        this->cold_selected = 0;
        this->drink_selected = 0;
        this->current_base = 0;
    }

    int init_base(){

        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                    base[i][j] = 0;
                }
        }

        return 1;

    }

    void draw_home(){
        for(int i = 0; i < ICON_H; i++){
            for(int j = 0; j < ICON_W; j++){
                if(this->home_selected)
                    base[i+7][j] = sel_home[i][j];
                else
                    base[i+7][j] = home[i][j];
            }
        }
    }

    void draw_hot(){
        for(int i = 0; i < ICON_H; i++){
            for(int j = 0; j < ICON_W; j++){
                if(this->hot_selected)
                    base[i+20][j] = sel_hot[i][j];
                else
                    base[i+20][j] = hot[i][j];
            }
        }
    }

    void draw_cold(){
        for(int i = 0; i < ICON_H; i++){
            for(int j = 0; j < ICON_W; j++){
                if(this->cold_selected)
                    base[i+33][j] = sel_cold[i][j];
                else
                    base[i+33][j] = cold[i][j];
            }
        }
    }

    void draw_drinks(){
        //lay out drink sprites on the base
        //origin : 5 13
        this->row_border = 0;
        this->col_border = 0;
        int o_w = 13;
        int o_h = 5;

        while(this->col_border < 4){
            o_w = 13;
            row_border = 0;
            while(row_border < 10){
                for(int i = 0; i < DRINK_H; i++){
                    for(int j = 0; j < DRINK_W; j++){
                        //print values
                        if( (this->col_border*10)+row_border != drink_selected)
                            base[o_h + i][o_w + j] = drink[i][j];
                        else
                            base[o_h + i][o_w + j] = sel_drink[i][j];
                    }
                }
                o_w = o_w + DRINK_W;
                row_border++;
            }
            o_h = o_h + DRINK_H;
            this->col_border++;
        }

    }

    void draw_hot_drinks(){

        this->row_border = 0;
        this->col_border = 0;
        int o_w = 13;
        int o_h = 5;

        while(this->col_border < 2){
            o_w = 13;
            row_border = 0;
            while(row_border < 6){
                for(int i = 0; i < DRINK_H; i++){
                    for(int j = 0; j < DRINK_W; j++){
                        //print values
                        if( (this->col_border*6)+row_border != drink_selected)
                            base[o_h + i][o_w + j] = drink[i][j];
                        else
                            base[o_h + i][o_w + j] = sel_drink[i][j];
                    }
                }
                o_w = o_w + DRINK_W;
                row_border++;
            }
            o_h = o_h + DRINK_H;
            this->col_border++;
        }
    }

    void draw_cold_drinks(){

        this->row_border = 0;
        this->col_border = 0;
        int o_w = 13;
        int o_h = 5;

        while(this->col_border < 3){
            o_w = 13;
            this->row_border = 0;
            while(this->row_border < 6){
                for(int i = 0; i < DRINK_H; i++){
                    for(int j = 0; j < DRINK_W; j++){
                        //print values
                        if( (this->col_border*6)+this->row_border != drink_selected)
                            base[o_h + i][o_w + j] = drink[i][j];
                        else
                            base[o_h + i][o_w + j] = sel_drink[i][j];
                    }
                }
                o_w = o_w + DRINK_W;
                this->row_border++;
            }
            o_h = o_h + DRINK_H;
            this->col_border++;
        }
    }

    void drawScreen(){
        //set base according to type
        clear();
        init_base();

        draw_home();
        draw_hot();
        draw_cold();

        if(this->current_base == 0){
            draw_drinks();
        }else if(this->current_base == 1){
            draw_hot_drinks();
        }else if(this->current_base == 2){
            draw_cold_drinks();
        }
        else{
            //empty
        }

        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                setPixel(j, i, base[i][j]);
            }
        }
       //draw borders
        drawRect(0, 0, 84, 48, FILL_TRANSPARENT);
        drawLine(12, 0, 12, 48, 1);
        
        refresh();

    }
//**********************************************************************************
};

#endif