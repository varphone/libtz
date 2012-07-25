#ifndef LIBTZ_TZ_H
#define LIBTZ_TZ_H

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

typedef void* tzinfo_t;     ///< Timezone information.

#define TZ_FLAG_POSIX    0x0000001      ///< Posix timezone format.

/// Lookup timezone information by full name.
/// @param [in] name            Full name of timezone.
/// @param [in] flags           Additional flags.
/// @return a tzinfo object if found.
tzinfo_t tz_lookup_by_name(const char* name, unsigned int flags);

/// Lookup timezone information by short name.
/// @param [in] name            Short name of timezone.
/// @param [in] flags           Additional flags.
/// @return a tzinfo object if found.
tzinfo_t tz_lookup_by_short_name(const char* short_name, unsigned int flags);

/// Lookup timezone information by full and short name.
/// @param [in] name            Full name of timezone.
/// @param [in] short_name      Short name of timezone.
/// @param [in] flags           Additional flags.
/// @return a tzinfo object if found.
tzinfo_t tz_lookup_by_full_and_short_name(const char* name, const char* short_name, unsigned int flags);

/// Lookup timezone information by timezone.
/// @param [in] tz              Timezone.
/// @param [in] flags           Additional flags.
/// @return a tzinfo object if found.
tzinfo_t tz_lookup_by_tz(struct timezone* tz, unsigned int flags);

/// Get full name.
/// @param [in] tzi             Timezone information object.
/// @return string pointer.
const char* tzinfo_name(tzinfo_t tzi);

/// Get short name.
/// @param [in] tzi             Timezone information object.
/// @return timezone pointer.
const char* tzinfo_short_name(tzinfo_t tzi);

/// Get timezone.
/// @param [in] tzi             Timezone information object.
/// @return string pointer.
const struct timezone* tzinfo_tz(tzinfo_t tzi);

#endif
