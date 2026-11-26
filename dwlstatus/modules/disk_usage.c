#include <stdio.h>
#include <sys/statvfs.h>

void output_disk(void) {
	struct statvfs st;
	if (statvfs("/", &st) != 0) return;
	unsigned long long total = (unsigned long long)st.f_blocks * st.f_frsize;
	unsigned long long free = (unsigned long long)st.f_bavail * st.f_frsize;
	unsigned long long used = total - free;
	double total_gib = total / (1024.0 * 1024.0 * 1024.0);
	double used_gib = used / (1024.0 * 1024.0 * 1024.0);
	printf("disk: %.1fGi/%.1fGi", used_gib, total_gib);
}
