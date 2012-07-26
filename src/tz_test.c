/*
 * Copyright (C) 2012 Varphone Wong <varphone@qq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public Licens
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-
 *
 */

#include <stdio.h>
#include "tz.h"

int main(int argc, char** argv)
{
    tzinfo_t tzi = tz_lookup_by_name("DatelineStandardTime12", TZ_FLAG_POSIX);
    if (tzi) {
        printf("name        : %s\n", tzinfo_name(tzi));
        printf("short name  : %s\n", tzinfo_short_name(tzi));
        printf("minuteswest : %d\n", tzinfo_tz(tzi)->tz_minuteswest);
        printf("dsttime     : %d\n", tzinfo_tz(tzi)->tz_dsttime);
    }
    return 0;
}
