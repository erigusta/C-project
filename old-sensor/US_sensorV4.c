#include <stdio.h>
#include "brick.h"
#include <unistd.h>
// as ex yro toutch
//#ifdef __WIN32__
//#include <windows.h>
// UNIX //////////////////////////////////////////
#else
#include <unistd.h>
// som i tacho etc
#define MOTOR_RIGHT OUT_A
#define MOTOR_LEFT  OUT_B
#define MOTOR_DUMP OUT_C

//sensor.h
// port INX_T type_inx
// Sensor I2C address.

#define Sleep( msec ) usleep(( msec ) * 1000 ) /*Definerar sleep där Sleep(1000)= 1 sekund*/

POOL_T usSensor; // kanske inte behöver men kan vara bra att ha om något i brick.h anvädner den struct
int usValue0 = 0;

int getDistanceFwd();
// använd gyro annars kommer det inte funka
void main(){
  /*if ( !brick_init()) return ( 1 ); /*Instansierar klossen och tillåter remote-connection*/
	printf( "*** ( EV3 ) Hello! ***\n" );
	Sleep(2000); // som i ex*/

  if(!sensor_is_plugged((LEGO_EV3_US), SENSOR_TYPE__NONE_)) {
		printf("Stoppa in US i port 3 \n");// ersett sensor_us med  lego_ev3_us
		brick_uninit();//behöver ej

	}
  // Detta är för att definiera innan man kallar på sensorn
  usSensor = sensor_search( LEGO_EV3_US ); //
  sensor_set_mode(usSensor , LEGO_EV3_US_US_DIST_CM); //CAPP change the sensor to dist mode
  int dist = getDistanceFwd();
  printf("%d \n",dist );// försnabt blink på skärmen, ssh, enhet cm/mm?
}

int getDistanceFwd(){//flera?
  return sensor_get_value(0, usSensor, 0);
  /*Vissa modes kan ha fler utdata, notera första parametern i sensor_get_value */
}
// fråga om namn på US sensor LEGO_EV3_IR eller annat,
