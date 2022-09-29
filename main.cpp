#include "mbed.h"

//#include "bin/stock_manager.h"
//#include "bin/payment_manager.h"
//#include "bin/card_reader.h"
#include "bin/Display.h"
#include "Joystick.h"

    //user inputs
    Display screen(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
    Joystick jt(PC_3,PC_2); //selector
    //sensors
    // CardReader cr(PA_1);
    // AnalogIn tmp(PC_3); //TEMP Sensor pin
    DigitalIn bt(PC_13); //selection button

int run();    
void jt_selector();
void bt_selector();

// main() runs in its own thread in the OS
int main(){

    //testing Display
    screen.init(LPH7366_1);
    screen.setContrast(0.55);
    screen.setBrightness(0.5);

    //adding Joystick
    jt.init();

    //adding button
    bt.mode(PullNone);
    //run program
    run();

    return 1;
}


int run(){
    //primary setup
    screen.init_base();
    screen.reset_values();
    screen.set_drink(0);
    screen.set_base(0);

    while(1){
        screen.drawScreen();
        jt_selector();
        bt_selector();

        ThisThread::sleep_for(120ms);
    }

    return 1;
}


void jt_selector(){
    //moves the selector based on the the current selection and user input
    if(screen.get_home()){
        //home selected currently
        if(jt.get_direction() == S){
            screen.set_home(0);
            screen.set_hot(1);
        
        }else if(jt.get_direction() == E){
            screen.set_home(0);
            screen.set_drink(0);
        }else{
            //empty
        }

    }else if (screen.get_hot()) {
        //hot selected currently
        if(jt.get_direction() == S){
            screen.set_hot(0);
            screen.set_cold(1);
        
        }else if(jt.get_direction() == E){
            screen.set_hot(0);
            screen.set_drink(screen.get_border_r());
        
        }else if(jt.get_direction() == N){
            screen.set_hot(0);
            screen.set_home(1);
        
        }else{
            //rmpty
        }

    }else if(screen.get_cold()){
        //cold selected currently
        if(jt.get_direction() == N){
            screen.set_cold(0);
            screen.set_hot(1);
        
        }else if(jt.get_direction() == E){
            screen.set_cold(0);
            screen.set_drink(2*screen.get_border_r());
        
        }else{
            //rmpty
        }
    }else{
        //if drink selected
        if(jt.get_direction() == N){

            if(screen.get_drink() >= 0 && screen.get_drink() < screen.get_border_r()){
                //dont move
            }
            else{
                screen.set_drink(screen.get_drink() - screen.get_border_r());
            }
        
        }else if(jt.get_direction() == S){

            if(screen.get_drink() >= (screen.get_border_c()-1)*screen.get_border_r() 
                && screen.get_drink() < screen.get_border_c()*screen.get_border_r()){
                //dont move
            }
            else{
                screen.set_drink(screen.get_drink() + screen.get_border_r());
            }
        
        }else if(jt.get_direction() == E){

            if( (screen.get_drink() - (screen.get_border_r()-1))
                    %   screen.get_border_r() == 0 ){
                //dont move
            }
            else{
                screen.set_drink(screen.get_drink() + 1);
            }

        
        }else if(jt.get_direction() == W){
            
            if(screen.get_drink()   %   screen.get_border_r() == 0 ){
                //dont move
                if(screen.get_drink() < screen.get_border_r()){
                    screen.set_drink(-1);
                    screen.set_home(1);
                
                }else if(screen.get_drink() < 2*screen.get_border_r()){
                    screen.set_drink(-1);
                    screen.set_hot(1);
                }else{
                    screen.set_drink(-1);
                    screen.set_cold(1);
                }

            }
            else{
                screen.set_drink(screen.get_drink() - 1);
            }
        
        }else{
            //empty
        }

    }


}

void bt_selector(){
    //waits for button input to change mode/proceed to next stage
    if(!bt.read()){
        if(screen.get_home()){
            //draw base screen
            screen.set_base(0);
        }else if(screen.get_hot()){
            //draw only hot drinks
            screen.set_base(1);

        }else if(screen.get_cold()){
            //draw only cold drinks
            screen.set_base(2);
        
        }else{
            //selected drinks

        }
    
    }else{
        //nothing
    }

}
