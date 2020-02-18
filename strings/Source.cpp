#include <conio.h>
#include <fstream>

namespace chili
{
	void print( const char* s )
	{
		for( ; *s != 0; s++ )
		{
			_putch( *s );
		}
	}
	void printContinue(const char* s)
	{
		int n = 0;
		for (; *s != 3; s++)
		{
			_putch(*s);
			n++;
		}
		while (n < 16)
		{
			_putch(' ');
			n++;
		}
	}

	void read( char* buf,int maxSize )
	{
		const char* const pEnd = buf + maxSize;
		for( char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(),buf++ )
		{
			_putch( c );
			*buf = c;
		}
		*buf = 0;
	}

	void readContinue(char* buf, int textEnd)
	{
		const char* const pEnd = buf + textEnd;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 3;
	}

	void readSave(char* buf, int textEnd)
	{
		const char* const pEnd = buf + textEnd;
		for (char c = _getch(); c != 13 && (buf + 5 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = '.';
		buf++;
		*buf = 't';
		buf++;
		*buf = 'x';
		buf++;
		*buf = 't';
		buf++;
		*buf = 0;
	}

	int str2int( const char* s )
	{
		// scan to start point
		const char* p = s;
		for( ; *p >= '0' && *p <= '9'; p++ );
		p--;

		int val = 0;
		int place = 1;
		// convert place values and accumulate
		for( ; p >= s; p-- )
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	int fib( int n )
	{
		if( n < 2 )
		{
			return n;
		}
		return fib( n - 1 ) + fib( n - 2 );
	}

	void strrev( char* pl )
	{
		// scan to start point
		char* pr = pl;
		for( ; *pr != 0; pr++ );
		pr--;

		for( ; pl < pr; pl++,pr-- )
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str( int val,char* buf,int size )
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for( ; val > 0 && (buf + 1 < pEnd); val /= 10,buf++ )
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev( pStart );
	}
}

int main()
{
	char c = 0;
	char data[201];
	int i = 0;
	for (char& c : data)
	{
		c = 3;
	}
	data[200] = 0;
	while (c != 'q')
	{
		chili::print("l(oad) s(ave) a(dd) q(quit) or p(rint)\n");
		c = _getch();
		switch (c)
		{
		case 'a':
			if (i < 200)
			{
				chili::print("nEnter name: ");
				chili::readContinue(&data[i], 17);
				i += 17;
				chili::print("\nEnter value: ");
				chili::readContinue(&data[i], 3);
				i += 3;
				_putch('\n');
			}
			else
			{
				chili::print("List full!\n");
			}
			break;
		case 'p':
		{
			const int temp = i;
			i = 0;
			chili::print("\n\tUgly Chart Pimps!");
			chili::print("\n\t++++++++++++++++\n\n");
			while (data[i] != 0)
			{
				if (data[i] != 3)
				{
					chili::printContinue(&data[i]);
					i += 17;
					_putch('\t|');
					char n = chili::str2int(&data[i]);
					if (n < 63)
					{
						while (n > 0)
						{
							_putch('=');
							n--;
						}
					}
					else
					{
						chili::print("OF THE CHARTS!!!!!!");
					}
					i += 3;
					_putch('\n');
				}
				else
				{
					i += 20;
				}
			}
			i = temp;
			chili::print("\n\n");
		}
			break;
		case 's':
		{
			char saveName[15];
			chili::print("Write save file name: ");
			chili::readSave(saveName, 15);
			std::ofstream out("saveTest0.txt", std::ios::binary);
			for (char c : data)
			{
				if (c = 0)
				{
					break;
				}
				out.put(c);
			}
			_putch('\n');
		}
			break;
		case 'l':
			chili::print("load");
		}
	}
	return 0;
}