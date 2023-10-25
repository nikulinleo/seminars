int MPU9250::begin(){

  
  // select clock source to gyro
  if(writeRegister(PWR_MGMNT_1,CLOCK_SEL_PLL) < 0){
    return -4;
  }
  // check the WHO AM I byte, expected value is 0x71 (decimal 113) or 0x73 (decimal 115)
  if((whoAmI() != 113)&&(whoAmI() != 115)){
    return -5;
  }
  // enable accelerometer and gyro
  if(writeRegister(PWR_MGMNT_2,SEN_ENABLE) < 0){
    return -6;
  }
  // setting accel range to 16G as default
  if(writeRegister(ACCEL_CONFIG,ACCEL_FS_SEL_16G) < 0){
    return -7;
  }
  _accelScale = G * 16.0f/32767.5f; // setting the accel scale to 16G
  _accelRange = ACCEL_RANGE_16G;
  // setting the gyro range to 2000DPS as default
  if(writeRegister(GYRO_CONFIG,GYRO_FS_SEL_2000DPS) < 0){
    return -8;
  }
  _gyroScale = 2000.0f/32767.5f * _d2r; // setting the gyro scale to 2000DPS
  _gyroRange = GYRO_RANGE_2000DPS;


  // setting bandwidth to 184Hz as default
  if(writeRegister(ACCEL_CONFIG2,ACCEL_DLPF_184) < 0){ 
    return -9;
  } 
  if(writeRegister(CONFIG,GYRO_DLPF_184) < 0){ // setting gyro bandwidth to 184Hz
    return -10;
  }
  _bandwidth = DLPF_BANDWIDTH_184HZ;
  // setting the sample rate divider to 0 as default
  if(writeRegister(SMPDIV,0x00) < 0){ 
    return -11;
  } 
  _srd = 0;
  return 1;
}
