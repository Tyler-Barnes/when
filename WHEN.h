// Tyler Barnes 2024
// The 'when' function is what happens when you !not the condition of a while loop
// It is only used when working on embedded programs or serial where the condition is updated by outside parameters
// I often find myself waiting on a register flag or pinstate to change before another action is taken
// I would write while(!digitalRead(pin)){} or similar. 
// So instead, I find it easier to read the logic as "when condition is true, then do the thing"
// rather than "while condition is not true, wait to proceed"

#define when(x) while(!(x)){}