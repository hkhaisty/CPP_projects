#include "thinker.h"

int main( )
{
    thinking_cap student;
    thinking_cap fan;
    student.slots( c_str("Hello"),  c_str("Goodbye"));
    fan.slots( "Go Cougars!", "Boo!");
    student.push_green( );
    fan.push_green( );
    student.push_red( );
    return 0;
}
