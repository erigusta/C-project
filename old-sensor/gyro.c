#include <stdio.h>
#include "brick.h"
#include <unistd.h>

#define Sleep( msec ) usleep(( msec ) * 1000 ) /*Definerar sleep där Sleep(1000)= 1 sekund*/

#define MOTOR_A    		OUTA
#define MOTOR_B    		OUTB
#define MOTOR_C    		OUTC
#define MOTOR_D    		OUTD
#define SENSOR_TOUCH	IN1
#define SENSOR_GYRO		IN2
#define SENSOR_3		IN3
#define SENSOR_4		IN4


POOL_T touchSensor;
int TouchReturnValue = 0;

POOL_T gyroSensor;
int gyroValue0 = 0;
int gyroValue1 = 0;

void main( void )
{

	if ( !brick_init()) return ( 1 ); /*Instansierar klossen och tillåter remote-connection*/
	printf( "*** ( EV3 ) Hello! ***\n" );
	Sleep(2000);

	if(!sensor_is_plugged((SENSOR_US|SENSOR_GYRO), SENSOR_TYPE__NONE_)) {
		printf("Stoppa in sensorer i port 1 och 2\n");
		brick_uninit();
		return(0);
	}
	/*Registrerar en sensor på sensor variabeln*/
	gyroSensor = sensor_search(LEGO_EV3_GYRO);

	/*Man kan antingen använda "Brick" bibliotekets förbyggda modes*/
	//touch_set_mode_touch(touchSensor);

	/*eller kolla i sensor.h filen på vilka modes som finns för alla olika sensorer*/
	sensor_set_mode(gyroSensor, us_set_mode_us_dist_cm );

	while(!TouchReturnValue){
		/*Vissa modes kan ha fler utdata, notera första parametern i sensor_get_value */
		gyroValue0 = sensor_get_value(0, gyroSensor, 0);
		gyroValue1 = sensor_get_value(1, gyroSensor, 0);
		printf("Gyro0: %d , Gyro1: %d \n", gyroValue0, gyroValue1 );

		Sleep(2000);
	}//alltid true
	brick_uninit();
}
