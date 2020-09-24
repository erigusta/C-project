

int main(){
  SetSensorLowspeed(IN_2);

  while(true){
    float distance = SensorUS(IN_2);
    if(dist > 10){
      OnFwd(OUT_A, 75);
      OnFwd(OUT_B, 75);
      // convert time to distance for robot
    }
    else{
      Off(OUT_A);
      Off(OUT_B);
    }
  }
  return 0;
}
