class Car{
    private:
        int forwardback1;
        int forwardback2;
        int leftright1;
        int leftright2;
        int lr_speed=0;
        int fb_speed=0;
        double m_speed=1.0;
    public:
        Car(const int fb1,const int fb2,const int lr1,const int lr2){
            forwardback1=fb1;
            forwardback2=fb2;
            leftright1=lr1;
            leftright2=lr2;
            pinMode(fb1,OUTPUT);
            pinMode(fb2,OUTPUT);
            pinMode(lr1,OUTPUT);
            pinMode(lr2,OUTPUT);
            return;
        }
        void set_fb_speed(int in){
            fb_speed=in;
            return;
        }
        void set_lr_speed(int in){
            lr_speed=in;
            return;
        }
        void stop(){
            set_fb_speed(0);
            set_lr_speed(0);
        }
        void set_m_speed(double in){
            m_speed=in;
            return;
        }
        void motor_turn(){
            if(fb_speed>0){
                analogWrite(forwardback2,(m_speed*fb_speed));
                analogWrite(forwardback1,0);
            }else if(fb_speed<0){
                analogWrite(forwardback2,0);
                analogWrite(forwardback1,-(m_speed*fb_speed));
            }else{
                analogWrite(forwardback2,0);
                analogWrite(forwardback1,0);
            }
            if(lr_speed>0){
                analogWrite(leftright2,lr_speed);
                analogWrite(leftright1,0);
            }else if(lr_speed<0){
                analogWrite(leftright2,0);
                analogWrite(leftright1,-lr_speed);
            }else{
                analogWrite(leftright2,0);
                analogWrite(leftright1,0);
            }
            return;
        }
};