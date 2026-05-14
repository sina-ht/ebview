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

/* This source derives from gtkcellrenerertext.h of GTK+-2.0.9
 * Here is an original copyright.
*/

/* gtkcellrenderertext.h
 * Copyright (C) 2000  Red Hat, Inc.,  Jonathan Blandford <jrb@redhat.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_CELL_RENDERER_COLOR_H__
#define __GTK_CELL_RENDERER_COLOR_H__

#include "defs.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define GTK_TYPE_CELL_RENDERER_COLOR		(gtk_cell_renderer_color_get_type ())
#define GTK_CELL_RENDERER_COLOR(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_CELL_RENDERER_COLOR, GtkCellRendererColor))
#define GTK_CELL_RENDERER_COLOR_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_CELL_RENDERER_COLOR, GtkCellRendererColorClass))
#define GTK_IS_CELL_RENDERER_COLOR(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_CELL_RENDERER_COLOR))
#define GTK_IS_CELL_RENDERER_COLOR_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_CELL_RENDERER_COLOR))
#define GTK_CELL_RENDERER_COLOR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_CELL_RENDERER_COLOR, GtkCellRendererColorClass))

typedef struct _GtkCellRendererColor      GtkCellRendererColor;
typedef struct _GtkCellRendererColorClass GtkCellRendererColorClass;

struct _GtkCellRendererColor
{
	GtkCellRenderer parent_instance;
	gchar *color;
	gint width;
	gint height;
};

struct _GtkCellRendererColorClass
{
  GtkCellRendererClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};

GType            gtk_cell_renderer_color_get_type (void);
GtkCellRenderer *gtk_cell_renderer_color_new      (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __GTK_CELL_RENDERER_COLOR_H__ */
