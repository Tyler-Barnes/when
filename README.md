The idea behind this macro was to help the code read more logically when polling for a register update or pin state to change in embedded programming. 

I very often found myself making a while loop and checking for the opposite condition that I really cared about in order to poll for a certain condition to be true. 

In the case of AVR programming, lets imagine you are polling a register flag manually, and you don't want to move until the condition becomes true.   

One might code the following: 
  while (!ACSR & 0x20) {}  // wait for analog comparator to fire
  doSomething();           // do something afterwards

However, I don't find this to read very intuitively. You are saying "while the condition I want is not true, wait utill it is".
  
I would much rather read it as if to say "when the condition I want becomes true, do something".

Using a when() loop would turn the above example into: 
  when (ACSR & 0x20) {  // wait for analog comparator to fire
    doSomething();      // do something afterwards
  }

This has the added advantage of creating another scope for local variables if you want to declare some within the new {}Brackets. 

It is also useful when waiting for and reading serial data.
  when (Serial.available()) {
    newChar = Serial.read();
  } 
