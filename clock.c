#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	static char clock[] =
		"=============\n" // offsets
		"|    xii    |\n" // 14
		"|  xi   ii  |\n" // 28
		"|ix   o  iii|\n" // 42
		"| vii   iv  |\n" // 56
		"|    vi     |\n" // 70
		"=============";
	
	int min;
	int hour;
	
	if (argc > 2) goto usage;
	
	if (argc == 1)
	{
		time_t now = time(NULL);
		struct tm tm = *localtime(&now);
		min = tm.tm_min;
		hour = tm.tm_hour;
	}
	
	if (argc == 2)
	{
		char *arg = argv[1];
		
		if (*arg == '1' && arg[1] != ':')
		{
			hour = 10,
			arg++;
			if (*arg > '2') goto usage;
		}
		else
		{
			hour = 0;
			if (*arg > '9') goto usage;
		}
		
		if (*arg < '0') goto usage;
		
		hour += *arg - '0';
		arg++;
		
		if (*arg != ':') goto usage;
		arg++;
		
		if (*arg < '0') goto usage;
		if (*arg > '5') goto usage;
		
		min = (*arg - '0') * 10;
		arg++;
		
		if (*arg < '0') goto usage;
		if (*arg > '5') goto usage;
		
		min += *arg - '0';
		arg++;
		
		if (*arg != '\0') goto usage;
	}
	
	switch (hour % 12)
	{
		case 0: clock[34] = ','; break;
		case 1: clock[35] = ','; break;
		
		case 5: clock[63] = '`'; break;
		case 6: clock[62] = '\''; break;
		case 7: clock[61] = '\''; break;
		
		case 11: clock[33] = '.'; break;
	}
	
	switch (min / 5)
	{
		case 0: clock[34] = '|'; break;
		case 1:
		case 2: clock[35] = '/'; break;
		case 3: clock[49] = clock[50] = '-'; break;
		case 4:
		case 5: clock[63] = '\\'; break;
		case 6: clock[62] = '|'; break;
		case 7:
		case 8: clock[61] = '/'; break;
		case 9: clock[45] = clock[46] = '-'; break;
		case 10:
		case 11: clock[33] = '\\'; break;
	}
	
	switch (hour % 12)
	{
		case 2: clock[49] = '\''; break;
		case 3: clock[49] = '-'; break;
		case 4: clock[49] = '.'; break;
		
		case 8: clock[47] = ','; break;
		case 9: clock[47] = '-'; break;
		case 10: clock[47] = '`'; break;
	}
	
	puts(clock);
	return 0;
	
	usage:
	fprintf(stderr, "usage: %s [HH:SS]\nnote: 0 < HH <= 12\nand: 0 <= MM < 60\n", *argv);
	return 1;
}
