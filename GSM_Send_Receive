//Function Prototypes
void initialize(); //initialize ports
void sendMsg(char*); //send sms
char* sendGSMCommand(char*); //send AT command
int dataRead();
void UART_Write_Line(char*); //uart write text with CR and LF
int strSearch(char[], int, char[]);
void UART1_Read_Text(char *Output,char *Delimiter,char Attemps);
//Global Variables
const char *recepientNumber = "09108738692";
const unsigned int SIZE_BUFFER = 125;
void main(){
     initialize();

     while(1){
    // sendMsg("hello");
     dataRead();

     }
}

void initialize(){
     ADCON1 = 0x80;
     TRISC = 0x80;

     UART1_Init(9600);
     Delay_ms(100);
     sendGSMCommand("AT+CNMI=1,0,2,0,1\n\r"); //configure New Message Indicator
     sendGSMCommand("AT+CMGF=1\r\n");
}

char* sendGSMCommand(char *cmd){
      char response[255];
      char in;
      int i;
      PORTD.F2 = 1;
      UART1_Write_Text(cmd);
      Delay_ms(500);
      if(UART1_Data_Ready()){
            for(i=0; UART1_Data_Ready(); i++){
                 in = UART1_Read();
                 response[i] = in;
            }
            response[i] = '\n';
      }
      PORTD.F2 = 0;
      return response;
}


void sendMsg(char *msg){

     char in;
     int i;
     PORTD.F1 = 1;
     UART1_Write_Text("AT+CMGS=\"");
     for(i=0; i < 11; i++)
              UART1_Write(*(recepientNumber+i));
     UART1_Write_Text("\"\r\n");
     Delay_ms(1000);
     if(UART1_Data_Ready()){
            for(i=0; UART1_Data_Ready(); i++){
                 in = UART1_Read();
            }
      }
      UART1_Write_Text(msg);
      Delay_ms(1000);
      UART1_Write(26);
      Delay_ms(500);

      UART1_Write_Text("AT+CMGL=""ALL""");    //
    Delay_ms(500);                 //
      UART1_Write_Text("AT+CMGD=1,4");
      PORTD.F1 = 0;
}
void UART_Write_Line(char *msg){ //for debugging purposes only
     UART1_Write_Text(msg);
     Delay_ms(100);
     UART1_Write(0x0A);
     UART1_Write(0x0D);
}

int dataRead(){
    int i;
    char x[SIZE_BUFFER];
    char msg[] = "REQ";
    char *xptr;
    int q = 75;
    i=0;
    UART1_Write_Text("AT+CMGL=""ALL""");    //
    Delay_ms(500);                         //
    UART1_Write_Text("AT+CMGF=1\r\n");
    UART1_Write_Text("AT+CMGR=1\r\n");
    Delay_ms(500);
    //UART1_Read_Text(x[i],"REQ",20);
    x[i]= UART1_Read();
    while(!UART1_Data_Ready()){};
    //for(i=0; UART1_Data_Ready(); i++){
    UART1_Read_Text(x[i],"REQ",20);
    sendMsg("HOYYYYY12345\r\n");

    //}
        Delay_ms(300);

        //UART1_Write_Text(" HOY12345");
        // sendMsg("HOYYYYY12345\r\n");
      //  sendMsg(x[i]);
        
        
    if(strSearch(x, strlen(x), "REQ")) return 1;
    return 0;
    //sendMsg(*msg);       //GINDUGANG
}

int strSearch(char x[], int xLen, char str[]){
    int i, y;
    for(i = 0; i < xLen - 1; i++){
         if(x[i] == str[0]){
             for(y=0; y < strlen(str); y++, i++){
                 if(x[i] == str[y]){
                     if(y == strlen(str) - 1 && x[i] == str[y]) return 1;
                     else continue;
                 }else break;
             }
         }
    }
    return 0;
}
//Ga loop lg xa send. Wala ga delete
