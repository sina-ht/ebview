/*  Copyright (C) 2001-2004  Kenichi Suto
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <stdio.h>
#include <stdarg.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <string.h>

#include "dialog.h"
#include "log.h"

#define STDERR stderr


gint ebview_log_level = LOG_MESSAGE;
//gint ebview_log_level = LOG_DEBUG;

void set_log_level(gint level){
	ebview_log_level = level;
}

void log_func(const gchar *file, gint line, LOG_LEVEL level, const gchar *message, ...){
	va_list ap;
	gchar format[1024];
	gchar str[1024];

	va_start(ap, message);
	vsnprintf(str, 1024, message, ap);
	va_end(ap);

	if(level <= ebview_log_level) {
		char *prefix;

		switch(level){
		case LOG_ERROR:
			prefix = "ERROR";
			break;
		case LOG_CRITICAL:
			prefix = "CRITICAL";
			break;
		case LOG_WARNING:
			prefix = "WARNING";
			break;
		case LOG_MESSAGE:
			prefix = "MESSAGE";
			break;
		case LOG_INFO:
			prefix = "INFO";
			break;
		case LOG_DEBUG:
			prefix = "DEBUG";
			break;
		}

		g_printf("%s:%d %s : %s\n", file, line, prefix, str);
	}

	// Show dialog box.
#if 0
	if(level <= LOG_MESSAGE){
		switch(level){
		case LOG_ERROR:
		case LOG_CRITICAL:
			popup_error(str);
			break;
		case LOG_WARNING:
		case LOG_MESSAGE:
			popup_warning(str);
			break;
		default:
			break;
		}
	}
#endif
}
