float pulseCount = 0;
float temp = 0;
int cnt = 0;
void initPorts();

void main() {
     char rqst;
     char pulseStr[12];
     initPorts();
     while(1){
         if(PORTB.F0 == 1){
            temp = pulseCount;

           pulseCount += 0.00000625; //1/1600
          //   pulseCount = pulseCount * 1600 / 1600000 ;
            if(pulseCount - temp > 5){
                pulseCount = temp;
            }
            PORTB.F4 = 1;
            while(PORTA.F0== 1){}
            PORTB.F4 = 0;
         }
         if(UART1_Data_Ready()){
              rqst = UART1_Read();
              if(rqst == '*'){
                   FloatToStr(pulseCount, pulseStr);
                   UART1_Write_Text(pulseStr);

                  // UART1_Write_Text(Read_Time); //RTC Display Time
                   UART1_Write(0x0A);
                   UART1_Write(0x0D);
                   Delay_ms(500);


              }

         }
     }
}

void initPorts(){
     ADCON1 = 0x07;
     TRISB = 0x0F;
     TRISD = 0x00;
     UART1_Init(9600);
}
