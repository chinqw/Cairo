#include <stdlib.h>
#include "backend.h"

static cairo_surface_t *image_backend_create_surface(Rcairo_backend* be, int width, int height)
{
  int stride = 4 * width;
  void *buf = (void*) malloc (stride * height);
  /* start off with fully transparent image */
  memset(buf, 0xff, stride * height);
  
  return cairo_image_surface_create_for_data (buf,
					      CAIRO_FORMAT_ARGB32,
					      width, height, stride);
}

static void image_backend_destroy_surface(Rcairo_backend* be)
{
}

Rcairo_backend *Rcairo_new_image_backend()
{
  Rcairo_backend *be = (Rcairo_backend*) malloc(sizeof(Rcairo_backend));
  be->user = 0;
  be->create_surface = image_backend_create_surface;
  be->destroy_surface = image_backend_destroy_surface;
  be->locator = 0; /* unsupported (img is non-interactive) */
  return be;
}

