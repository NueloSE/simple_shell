#include "main.h"

/**
 * int_to_str - converts integer to string
 * @value: the integer
 * @buffer: the newstring
 * Return: len of the new string
*/

int int_to_str(int value, char *buffer)
{
	int len = 0;
	int temp = value;

	do {
		len++;
		temp /= 10;
	} while (temp != 0);

	buffer += len;
	*buffer = '\0';

	do {
		buffer--;
		*buffer = '0' + value % 10;
		value /= 10;
	} while (value != 0);

	return (len);
}

/**
 * _fprintf - sends formatted string to the stderr file
 * @format: formated string
 * Return: Always void
*/

void _fprintf(const char *format, ...)
{
	char buffer[4096];
	va_list args;
	const char *str_arg, *p;
	char *buf_ptr;
	int int_arg, len;

	va_start(args, format);
	p = format;
	buf_ptr = buffer;

	while (*p != '\0')
	{
		if (*p == '%' && *(p + 1) != '\0')
		{
			if (*(p + 1) == 's')
		{
			p += 2;
			str_arg = va_arg(args, const char*);

			while (*str_arg != '\0')
				*buf_ptr++ = *str_arg++;
		}
		else if (*(p + 1) == 'd')
		{
			p += 2;
			int_arg = va_arg(args, int);
			len = int_to_str(int_arg, buf_ptr);

			buf_ptr += len;
		}
		else
			*buf_ptr++ = *p++;
		}
		else
		*buf_ptr++ = *p++;
	}

	va_end(args);

	write(STDERR_FILENO, buffer, buf_ptr - buffer);
	}

/**
 * _printf - prints formated string to the stdout
 * @format: the formated string
 * Return: Alway void
*/

void _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			const char *value = va_arg(args, const char*);

			printf("%s", value);
			format += 2;
		}
		else
		{
		putchar(*format);
		format++;
		}
	}

	va_end(args);
}
