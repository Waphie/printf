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
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
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
    _printf("Education is when you read the fine print. Experience is what you get if you don't.\n");
    _printf("Here is a character: %c\n", 'V');
    _printf("Here is a string: %s\n", "Hey, Class!");
    _printf("Here is a percent sign: %%\n");
    _printf("Here is an integer: %d\n", 23);

    return 0;
}
