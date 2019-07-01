int static kk ;
unsigned long times = 1000;

void setup()
{   
  Serial.begin(9600);
//   pinMode(ledPin, OUTPUT);
   pinMode(2, INPUT_PULLUP); // sử dụng điện trở kéo lên cho chân số 2, ngắt 0
   attachInterrupt(0, test, HIGH); // gọi hàm tatled liên tục khi còn nhấn nút
}

void loop()
{
 if(millis()>times)
 {
    noInterrupts();
    Serial.println(kk); 
    kk=0;
    times+=1000;
    interrupts();
  }
}

void test()
{    
    kk++; 
}
