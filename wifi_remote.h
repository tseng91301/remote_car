const char* ssid = "KK coder's car";
ESP8266WebServer server(80);

void handle_command(String raw,Car &carin){
    static String pre="";
    if(raw==pre){
        return;
    }else{
        pre=raw;
    }
    char c1=raw[0];
    if(!((c1>='1'&&c1<='9')||(c1>='A'&&c1<='Z'))){
        return;
    }
    if(range((int)c1,(int)'0',(int)'9')){
        double spd=(double)((int)c1-48+1)/(double)10;
        Serial.println(spd);
        carin.set_m_speed(spd);
    }
    if(c1=='F'){
        carin.set_fb_speed(255);
    }else if(c1=='B'){
        carin.set_fb_speed(-255);
    }else if(c1=='L'){
        carin.set_lr_speed(150);
    }else if(c1=='R'){
        carin.set_lr_speed(-150);
    }else if(c1=='S'){
        carin.stop();
    }else if(c1=='I'){
        carin.set_fb_speed(255);
        carin.set_lr_speed(-150);
    }else if(c1=='G'){
        carin.set_fb_speed(255);
        carin.set_lr_speed(150);
    }else if(c1=='J'){
        carin.set_fb_speed(-255);
        carin.set_lr_speed(-150);
    }else if(c1=='H'){
        carin.set_fb_speed(-255);
        carin.set_lr_speed(150);
    }else if(c1=='T'){
        carin.set_lr_speed(0);
    }
}

void HTTP_handleRoot(void) {
    if( server.hasArg("State") ){
        Serial.println(server.arg("State"));
        server.send ( 200, "text/html", "" );
    }else{
        server.send ( 200, "text/html", remote_html );
        delay(1);
    }
}






