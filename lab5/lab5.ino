int photo_pin(A0);
int val1=0;
unsigned int val=0;
unsigned int counter=0;
int integer_arr[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  Serial.setTimeout(100);
}

void loop() {

  int count_samples=0;
  int mean=0;
  // Get 10 samples into an array
  while(count_samples < 10){
    val=Serial.parseInt();
    analogWrite(5,counter); // Change duty cycle
    val1 = analogRead(photo_pin);
    integer_arr[count_samples] = val1;
    count_samples++;
    mean+= val1;
  }

  // Calculate standard deviation and remove values that fall outside of it
  mean = mean/10;
  // Calculate the variance
  float variance_total=0;
  int variance_count=0;
  while(variance_count < 10){
    int power_val = (integer_arr[variance_count] - mean) * (integer_arr[variance_count] - mean);
    variance_total += power_val;
    variance_count++;
  }
  
  // Get the standard deviation
  variance_total = variance_total/10;
  int sd = sqrt(variance_total);

  // Remove values over 1 SD away from the mean
  // Add remaining values and take the avg; this will be the avg of the valid sample data
  int avg_of_sample=0;
  int num_of_valid_samples=0;
  for(int i=0; i<10; i++){
    if(abs(integer_arr[i] - mean) < variance_total){
      avg_of_sample += integer_arr[i];
      num_of_valid_samples++;
    }
  }

  Serial.println(abs(avg_of_sample/num_of_valid_samples));
  
  counter+=2.55; // increment the LED duty cycle after getting samples
}
