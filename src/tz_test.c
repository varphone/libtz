#include <stdio.h>
#include "tz.h"

int main(int argc, char** argv)
{
    tzinfo_t tzi = tz_lookup_by_name("DatelineStandardTime12", TZ_FLAG_POSIX);
    printf("name        : %s\n", tzinfo_name(tzi));
    printf("short name  : %s\n", tzinfo_short_name(tzi));
    printf("minuteswest : %d\n", tzinfo_tz(tzi)->tz_minuteswest);
    printf("dsttime     : %d\n", tzinfo_tz(tzi)->tz_dsttime);
    return 0;
}
