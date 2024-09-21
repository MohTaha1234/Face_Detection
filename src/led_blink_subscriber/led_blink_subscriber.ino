#include <ros.h>

/* 
 * rosserial Subscriber Example
 * Blinks an LED based on the received message
 */
#include <std_msgs/Int32.h>

// Create a ROS node handle
ros::NodeHandle nodeHandle;

// Callback function to handle incoming messages
void messageCallback(const std_msgs::Int32& msg) {
  // Set the LED state based on the received data
  if (msg.data == 1) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
  } else {
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
  }
}

// Create a ROS subscriber object
ros::Subscriber<std_msgs::Int32> subscriber("/face_detectorstatus", &messageCallback);

void setup() { 
  // Initialize the LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the ROS node
  nodeHandle.initNode();

  // Subscribe to the ROS topic
  nodeHandle.subscribe(subscriber);
}

void loop() {  
  // Process incoming messages
  nodeHandle.spinOnce();

  // Small delay to prevent excessive CPU usage
  delay(10);
}
