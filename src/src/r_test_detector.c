#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <stdlib.h>
#include "darknet.h"
#include "detector.h"

SEXP r_run_detector(SEXP thresh_in, SEXP weight_file_in) {
  PROTECT(weight_file_in = AS_CHARACTER(weight_file_in));
  char * weight_file;
  weight_file = R_alloc(strlen(CHAR(STRING_ELT(weight_file_in, 0))), sizeof(char));
  strcpy(weight_file, CHAR(STRING_ELT(weight_file_in, 0)));
  Rprintf("weight_file: %s\n", weight_file); 

  PROTECT(thresh_in = AS_NUMERIC(thresh_in));
  double *xT;
  xT = NUMERIC_POINTER(thresh_in);
  float thresh = (float) * xT;

  float hier_thresh = 0.5;
  int display = 0;
  test_detector("cfg/coco.dat", "cfg/yolo.cfg", weight_file, "data/dog.jpg", 
                thresh, hier_thresh, "out.jpg", display);
  UNPROTECT(1);
  return thresh_in;
}


