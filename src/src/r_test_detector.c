#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <stdlib.h>
#include "darknet.h"
#include "detector.h"

SEXP r_run_detector(SEXP thresh_in) {

  PROTECT(thresh_in = AS_NUMERIC(thresh_in));
  double *xT;
  xT = NUMERIC_POINTER(thresh_in);
  float thresh = (float) * xT;

  float hier_thresh = 0.5;
  int display = 0;
  test_detector("cfg/coco.dat", "cfg/yolo.cfg", "cfg/yolo.weights", "data/dog.jpg", 
                thresh, hier_thresh, "out.jpg", display);
  UNPROTECT(1);
  return thresh_in;
}


