/*
 * This file is part of fitbitd.
 *
 * fitbitd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * fitbitd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with fitbitd.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <errno.h>
#include <sys/sysinfo.h>

#define LOG_TAG "fitbitd-utils"
#include "log.h"

#include "fitbitd-utils.h"

long get_uptime(void)
{
    struct sysinfo info;

    if (sysinfo(&info)) {
        ERR("sysinfo failure %d\n", errno);
        return 0;
    }

    return info.uptime;
}
