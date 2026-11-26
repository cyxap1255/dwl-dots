#include <stdio.h>
#include <time.h>

void output_time(void) {
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);
	printf("%02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
}
