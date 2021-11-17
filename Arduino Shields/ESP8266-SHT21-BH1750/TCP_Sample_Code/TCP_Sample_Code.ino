void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // set serial buad rate to 115200 which is ESP86 buad rate
  delay(1000);

  //Initial ESP8266
  Serial.write("AT+CIPMUX=1\r\n"); //Enable multiple connections 
  delay(1000);
  Serial.write("AT+CWMODE=2\r\n"); //set WIFI mode to AP
  delay(1000);
  Serial.write("AT+CIPSTA=\"192.168.1.85\"\r\n"); // Set IP address of ESP8266 station
  delay(1000);
  Serial.write("AT+CIPSERVER=1,1010\r\n"); //make TCP Server with port 1010
  delay(1000);
  Serial.write("AT+CWSAP=\"AP_Name\",\"AP_PASSWORD\",5,3"); // Configuration of softAP mode name:AP_Name, password: AP_PASSWORD, channel: 5, encryption: WPA2_PSK
  delay(1000);

}

void loop() {
   
  //////////Transmit//////////////
  String s; //the string wich you want to send
  s.concat("add some string") ; //add some string
  s.concat(String(12)) ; //add some number
  s.concat(String("\r\n")) ; // add next line id you want  
  
  String sendCommand = "AT+CIPSEND=0,"; // make ESP command 
  sendCommand.concat(String(s.length())); // must add length of data wich you want to send
  sendCommand.concat(String("\r\n")) ; // you most add /r and /n at end of any ESP command
  
  Serial.print(sendCommand); // send command
  delay(200); // short delay to be sure ESP is ready for send data; actully must check recive ">" but short delay is easier way
  Serial.print(s); // send data  

}
