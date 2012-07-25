#if HAVE_ASSERT_H
#include <assert.h>
#else
#define assert(x)   do {} while (0)
#endif
#if HAVE_STRING_H
#include <string.h>
#endif
#include "tz.h"

struct tzinfo
{
    const char* name;
    const char* short_name;
    struct timezone tz;
};

struct tzinfo posix_1003_1_tzinfo[] = {
    {"DatelineStandardTime12", "UTC-12:00", {-720, 0}},
    {"<UTC-11>11", "UTC-11:00", {-660, 1}},
    {"HawaiianStandardTime10", "UTC-10:00", {-600, 0}},
    {"AlaskanStandardTime9DaylightTime,M3.2.0,M11.1.0", "UTC-9:00", {-540, 1}},
    {"PacificStandardTime8DaylightTime,M3.2.0,M11.1.0", "UTC-8:00", {-480, 1}},
    {"PacificStandardTimeMexico8DaylightTime,M4.1.0,M10.5.0", "UTC-8:00", {-480, 1}},
    {"MountainStandardTimeMexico7DaylightTime,M4.1.0,M10.5.0", "UTC-7:00", {-420, 1}},
    {"MountainStandardTime7DaylightTime,M3.2.0,M11.1.0", "UTC-7:00", {-420, 1}},
    {"USMountainStandardTime7", "UTC-7:00", {-420, 0}},
    {"CentralStandardTimeMexico6DaylightTime,M4.1.0,M10.5.0", "UTC-6:00", {-360, 1}},
    {"CanadaCentralStandardTime6", "UTC-6:00", {-360, 0}},
    {"CentralStandardTime6DaylightTime,M3.2.0,M11.1.0", "UTC-6:00", {-360, 1}},
    {"CentralAmericaStandardTime6", "UTC-6:00", {-360, 0}},
    {"SAPacificStandardTime5", "UTC-5:00", {-300, 0}},
    {"EasternStandardTime5DaylightTime,M3.2.0,M11.1.0", "UTC-5:00", {-300, 1}},
    {"USEasternStandardTime5DaylightTime,M3.2.0,M11.1.0", "UTC-5:00", {-300, 1}},
    {"VenezuelaStandardTime4:30", "UTC-4:30", {-270, 0}},
    {"AtlanticStandardTime4DaylightTime,M3.2.0,M11.1.0", "UTC-4:00", {-240, 1}},
    {"CentralBrazilianStandardTime4DaylightTime,M10.3.6/23:59:59,M2.4.6/23:59:59", "UTC-4:00", {-240, 1}},
    {"SAWesternStandardTime4", "UTC-4:00", {-240, 0}},
    {"PacificSAStandardTime4DaylightTime,M10.2.6/23:59:59,M3.2.6/23:59:59", "UTC-4:00", {-240, 1}},
    {"ParaguayStandardTime4DaylightTime,M10.1.6/23:59:59,M4.1.6/23:59:59", "UTC-4:00", {-240, 1}},
    {"NewfoundlandStandardTime3:30DaylightTime,M3.2.0,M11.1.0", "UTC-3:30", {-210, 1}},
    {"ESouthAmericaStandardTime3DaylightTime,M10.3.6/23:59:59,M2.4.6/23:59:59", "UTC-3:00", {-180, 1}},
    {"ArgentinaStandardTime3", "UTC-3:00", {-180, 0}},
    {"GreenlandStandardTime3DaylightTime,M3.4.6/22,M10.5.6/23", "UTC-3:00", {-180, 1}},
    {"SAEasternStandardTime3", "UTC-3:00", {-180, 0}},
    {"MontevideoStandardTime3DaylightTime,M10.1.0,M3.2.0", "UTC-3:00", {-180, 1}},
    {"BahiaStandardTime3DaylightTime,M10.3.6/23:59:59,M2.4.6/23:59:59", "UTC-3:00", {-180, 1}},
    {"<UTC-02>2", "UTC-2:00", {-120, 0}},
    {"<Mid-AtlanticStandardTime>2DaylightTime,M3.5.0,M9.5.0", "UTC-2:00", {-120, 1}},
    {"CapeVerdeStandardTime1", "UTC-1:00", {-60, 0}},
    {"AzoresStandardTime1DaylightTime,M3.5.0,M10.5.0/3", "UTC-1:00", {-60, 1}},
    {"GMTStandardTime0DaylightTime,M3.5.0/1,M10.5.0", "UTC-0:00", {-0, 1}},
    {"MoroccoStandardTime0", "UTC-0:00", {-0, 0}},
    {"GreenwichStandardTime0", "UTC-0:00", {-0, 0}},
    {"UTC0", "UTC-0:00", {0, 0}},
    {"WEuropeStandardTime-1DaylightTime,M3.5.0,M10.5.0/3", "UTC+1:00", {60, 1}},
    {"CentralEuropeStandardTime-1DaylightTime,M3.5.0,M10.5.0/3", "UTC+1:00", {60, 1}},
    {"RomanceStandardTime-1DaylightTime,M3.5.0,M10.5.0/3", "UTC+1:00", {60, 1}},
    {"CentralEuropeanStandardTime-1DaylightTime,M3.5.0,M10.5.0/3", "UTC+1:00", {60, 1}},
    {"NamibiaStandardTime-1DaylightTime,M9.1.0,M4.1.0", "UTC+1:00", {60, 1}},
    {"WCentralAfricaStandardTime-1", "UTC+1:00", {60, 0}},
    {"JordanStandardTime-2DaylightTime,M3.5.4/23:59:59,M10.5.5/1", "UTC+2:00", {120, 1}},
    {"MiddleEastStandardTime-2DaylightTime,M3.4.6/23:59:59,M10.5.6/23:59:59", "UTC+2:00", {120, 1}},
    {"SyriaStandardTime-2DaylightTime,M4.1.4/23:59:59,M10.5.4/23:59:59", "UTC+2:00", {120, 1}},
    {"SouthAfricaStandardTime-2", "UTC+2:00", {120, 0}},
    {"FLEStandardTime-2DaylightTime,M3.5.0/3,M10.5.0/4", "UTC+2:00", {120, 1}},
    {"EgyptStandardTime-2", "UTC+2:00", {120, 0}},
    {"EEuropeStandardTime-2DaylightTime,M3.5.0,M10.5.0/3", "UTC+2:00", {120, 1}},
    {"GTBStandardTime-2DaylightTime,M3.5.0/3,M10.5.0/4", "UTC+2:00", {120, 1}},
    {"IsraelStandardTime-2DaylightTime,M3.5.5,M9.4.0", "UTC+2:00", {120, 1}},
    {"TurkeyStandardTime-2DaylightTime,M3.5.0/3,M10.5.0/4", "UTC+2:00", {120, 1}},
    {"ArabicStandardTime-3", "UTC+3:00", {180, 0}},
    {"KaliningradStandardTime-3", "UTC+3:00", {180, 0}},
    {"ArabStandardTime-3", "UTC+3:00", {180, 0}},
    {"EAfricaStandardTime-3", "UTC+3:00", {180, 0}},
    {"IranStandardTime-3:30DaylightTime,M3.3.6/23:59:59,M9.3.1/23:59:59", "UTC+3:30", {210, 1}},
    {"ArabianStandardTime-4", "UTC+4:00", {240, 0}},
    {"CaucasusStandardTime-4DaylightTime,M3.5.0,M10.5.0/3", "UTC+4:00", {240, 1}},
    {"AzerbaijanStandardTime-4DaylightTime,M3.5.0/4,M10.5.0/5", "UTC+4:00", {240, 1}},
    {"GeorgianStandardTime-4", "UTC+4:00", {240, 0}},
    {"MauritiusStandardTime-4", "UTC+4:00", {240, 0}},
    {"RussianStandardTime-4", "UTC+4:00", {240, 0}},
    {"AfghanistanStandardTime-4:30", "UTC+4:30", {270, 0}},
    {"WestAsiaStandardTime-5", "UTC+5:00", {300, 0}},
    {"PakistanStandardTime-5", "UTC+5:00", {300, 0}},
    {"IndiaStandardTime-5:30", "UTC+5:30", {330, 0}},
    {"SriLankaStandardTime-5:30", "UTC+5:30", {330, 0}},
    {"NepalStandardTime-5:45", "UTC+5:45", {345, 0}},
    {"CentralAsiaStandardTime-6", "UTC+6:00", {360, 0}},
    {"BangladeshStandardTime-6", "UTC+6:00", {360, 0}},
    {"EkaterinburgStandardTime-6", "UTC+6:00", {360, 0}},
    {"MyanmarStandardTime-6:30", "UTC+6:30", {390, 0}},
    {"SEAsiaStandardTime-7", "UTC+7:00", {420, 0}},
    {"NCentralAsiaStandardTime-7", "UTC+7:00", {420, 0}},
    {"ChinaStandardTime-8", "UTC+8:00", {480, 0}},
    {"SingaporeStandardTime-8", "UTC+8:00", {480, 0}},
    {"NorthAsiaStandardTime-8", "UTC+8:00", {480, 0}},
    {"WAustraliaStandardTime-8", "UTC+8:00", {480, 0}},
    {"TaipeiStandardTime-8", "UTC+8:00", {480, 0}},
    {"UlaanbaatarStandardTime-8", "UTC+8:00", {480, 0}},
    {"TokyoStandardTime-9", "UTC+9:00", {540, 0}},
    {"KoreaStandardTime-9", "UTC+9:00", {540, 0}},
    {"NorthAsiaEastStandardTime-9", "UTC+9:00", {540, 0}},
    {"CenAustraliaStandardTime-9:30DaylightTime,M10.1.0,M4.1.0/3", "UTC+9:30", {570, 1}},
    {"AUSCentralStandardTime-9:30", "UTC+9:30", {570, 0}},
    {"EAustraliaStandardTime-10", "UTC+10:00", {600, 0}},
    {"WestPacificStandardTime-10", "UTC+10:00", {600, 0}},
    {"TasmaniaStandardTime-10DaylightTime,M10.1.0,M4.1.0/3", "UTC+10:00", {600, 1}},
    {"AUSEasternStandardTime-10DaylightTime,M10.1.0,M4.1.0/3", "UTC+10:00", {600, 1}},
    {"YakutskStandardTime-10", "UTC+10:00", {600, 0}},
    {"VladivostokStandardTime-11", "UTC+11:00", {660, 0}},
    {"CentralPacificStandardTime-11", "UTC+11:00", {660, 0}},
    {"NewZealandStandardTime-12DaylightTime,M9.5.0,M4.1.0/3", "UTC+12:00", {720, 1}},
    {"KamchatkaStandardTime-12DaylightTime,M3.5.0,M10.5.0/3", "UTC+12:00", {720, 1}},
    {"FijiStandardTime-12DaylightTime,M10.4.0,M1.4.0/3", "UTC+12:00", {720, 1}},
    {"MagadanStandardTime-12", "UTC+12:00", {720, 0}},
    {"<UTC+12>-12", "UTC+12:00", {720, 0}},
    {"TongaStandardTime-13", "UTC+13:00", {780, 0}},
    {"SamoaStandardTime-13DaylightTime,M9.5.0/0,M4.1.0/1", "UTC+13:00", {780, 1}},
    {0, 0, {0, 0}},
};

tzinfo_t tz_lookup_by_name(const char* name, unsigned int flags)
{
    struct tzinfo* tzi = 0;
    if (flags & TZ_FLAG_POSIX) {
        tzi = posix_1003_1_tzinfo;
        while (tzi->name) {
            if (!strcmp(tzi->name, name))
                return tzi;
            tzi++;
        }
    }
    return 0;
}

tzinfo_t tz_lookup_by_short_name(const char* short_name, unsigned int flags)
{
    struct tzinfo* tzi = 0;
    if (flags & TZ_FLAG_POSIX) {
        tzi = posix_1003_1_tzinfo;
        while (tzi->name) {
            if (!strcmp(tzi->short_name, short_name))
                return tzi;
            tzi++;
        }
    }
    return 0;
}

tzinfo_t tz_lookup_by_full_and_short_name(const char* name, const char* short_name, unsigned int flags)
{
    struct tzinfo* tzi = 0;
    if (flags & TZ_FLAG_POSIX) {
        tzi = posix_1003_1_tzinfo;
        while (tzi->name) {
            if (!strcmp(tzi->name, name) &&
                !strcmp(tzi->short_name, short_name))
                return tzi;
            tzi++;
        }
    }
    return 0;
}

tzinfo_t tz_lookup_by_tz(struct timezone* tz, unsigned int flags)
{
    struct tzinfo* tzi = 0;
    if (flags & TZ_FLAG_POSIX) {
        tzi = posix_1003_1_tzinfo;
        while (tzi->name) {
            if (!memcmp(&tzi->tz, tz, sizeof(*tz)))
                return tzi;
            tzi++;
        }
    }
    return 0;
}

const char* tzinfo_name(tzinfo_t tzi)
{
    assert(tzi);
    return ((struct tzinfo*)tzi)->name;
}

const char* tzinfo_short_name(tzinfo_t tzi)
{
    assert(tzi);
    return ((struct tzinfo*)tzi)->short_name;
}

const struct timezone* tzinfo_tz(tzinfo_t tzi)
{
    assert(tzi);
    return &((struct tzinfo*)tzi)->tz;
}

