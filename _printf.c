#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - a function that produces output according to a format.
 * @format: format is a character string
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	const char *val_s;
	int count = 0;
	va_list list;

	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'c':
					_putchar(va_arg(list, int));
					count++;
					break;
				case 's':
					val_s = va_arg(list, const char *);
					while (*val_s != '\0')
					{
						_putchar(*val_s);
						val_s++;
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*(format + 1));
					count += 2;
					break;
			}
			format += 2;
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
	}
	va_end(list);

	return (count);

}
