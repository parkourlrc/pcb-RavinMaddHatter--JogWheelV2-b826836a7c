#define timeBetweenReads 10
long knobPositions[4];
long prevKnobPositions[4]={0,0,0,0};
ESP32Encoder encoder1;
ESP32Encoder encoder2;
ESP32Encoder encoder3;
ESP32Encoder encoder4;
ESP32Encoder wheel;
void initEncoders(){
  
  encoder1.attachHalfQuad(knob1A, knob1B);
  encoder2.attachHalfQuad(knob2A, knob2B);
  encoder3.attachHalfQuad(knob4A, knob4B);
  //wheel.attachHalfQuad(wheelA, wheelB);
  encoder4.attachHalfQuad(knob3A, knob3B);
  
}
//Encoder encoder1(knob1A, knob1B);
//Encoder encoder2(knob2A, knob2B);
//Encoder encoder3(knob3A, knob3B);
//Encoder encoder4(knob4A, knob4B);



elapsedMillis auxEncoderTime;
long prevKnobPos[4];
void readAuxEncoders(){
  if(auxEncoderTime>=timeBetweenReads){
    knobPositions[0] = encoder1.getCount();
    knobPositions[1] = encoder2.getCount();
    knobPositions[2] = encoder3.getCount();
    //knobPositions[3] = wheel.getCount();
    knobPositions[3] = encoder4.getCount();
    for(int i =0;i<4;i++){
      if (abs(knobPositions[i])>3){
        if(knobPositions[i]>0){
          Serial.print("knob ");
          Serial.print(i);
          Serial.print(" sending ");
          Serial.println(knobAssignmets[i][1]);
          Keyboard.press(knobAssignmets[i][1]);
          Keyboard.release(knobAssignmets[i][1]);
          
        }else{
          Keyboard.press(knobAssignmets[i][0]);
          Keyboard.release(knobAssignmets[i][0]);
        }
        switch(i){
          case 0:
            encoder1.clearCount();
            break;
          case 1:
            encoder2.clearCount();
            break;
          case 2:
            encoder3.clearCount();
            break;
          case 3:
            encoder4.clearCount();
            break;
        }
      }
    }
    

    auxEncoderTime=0;
  }
}
