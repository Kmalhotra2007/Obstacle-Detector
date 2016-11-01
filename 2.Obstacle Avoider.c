#pragma config(CircuitBoardType, typeCktBoardDuemilanove)
#pragma config(Sensor, dgtl8,  MPOSL,           sensorDigitalIn)
#pragma config(Sensor, dgtl9,  MPOSR,           sensorDigitalIn)
#pragma config(Sensor, dgtl10, M0,             sensorDigitalOut)
#pragma config(Sensor, dgtl11, M1,             sensorDigitalOut)
#pragma config(Sensor, dgtl12, M2,             sensorDigitalOut)
#pragma config(Sensor, dgtl13, M3,             sensorDigitalOut)




// MOTOR CONNECTIONS
//    R       L
//  +   -    -  +

task main()
{
  while(true)
  {
     if((SensorValue[MPOSL]==false)&&(SensorValue[MPOSR]==false))//obstacle in front of both sensor
   	 {
     			//Backward
					SensorValue[M0] = false;
  				SensorValue[M1] = true;
  				SensorValue[M2] = false;
  				SensorValue[M3] = true;
     			wait1Msec(500);

     		  //Left Turn
					SensorValue[M0] = true;
  				SensorValue[M1] = false;
  				SensorValue[M2] = false;
  				SensorValue[M3] = false;
   				wait1Msec(300);
     }

     else if((SensorValue[MPOSL]==false)&&(SensorValue[MPOSR]==true))//in front of left sensor
   	 {
     			//Right Turn
					SensorValue[M0] = false;
  				SensorValue[M1] = false;
  				SensorValue[M2] = true;
  				SensorValue[M3] = false;
	   }

     else if((SensorValue[MPOSL]==true)&&(SensorValue[MPOSR]==false))//in front of right sensor
   	 {
     			//Left Turn
					SensorValue[M0] = true;
  				SensorValue[M1] = false;
  				SensorValue[M2] = false;
  				SensorValue[M3] = false;
   	 }

   	 else
     {
          //Forward
       		SensorValue[M0] = true;
  				SensorValue[M1] = false;
  			  SensorValue[M2] = true;
  				SensorValue[M3] = false;
     }
  }
}
