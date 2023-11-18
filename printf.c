#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; // Move to the character after '%'
            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
                    break;
            }
        } else {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Siwa is a Twin. Siwa is a Twin. Life is really interesting.\n");
    _printf("Here is a number: %c\n", '12');
    _printf("Here is a string: %s\n", "Hey, Class!");
    _printf("Here is a percent sign: %%\n");

    return 0;
}
