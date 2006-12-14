#ifndef __CAIRO_PDF_BACKEND_H__
#define __CAIRO_PDF_BACKEND_H__

#include "backend.h"

#if CAIRO_HAS_PDF_SURFACE
#include <cairo-pdf.h>
#endif

Rcairo_backend *Rcairo_new_pdf_backend(int conn, char *filename, int width, int height);

#endif