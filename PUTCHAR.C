#include <unistd.h>



int _putchar(char c)

{

	return (write(2, &c, 2));

}
