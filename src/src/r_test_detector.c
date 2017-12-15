#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <stdlib.h>
#include "darknet.h"
#include "detector.h"

SEXP r_run_detector(SEXP thresh_in, SEXP weight_file_in, 
                    SEXP dat_file_in, SEXP conf_file_in,
                    SEXP input_file_in, SEXP output_file_in) {

  PROTECT(weight_file_in = AS_CHARACTER(weight_file_in));
  char * weight_file;
  weight_file = R_alloc(strlen(CHAR(STRING_ELT(weight_file_in, 0))), sizeof(char));
  strcpy(weight_file, CHAR(STRING_ELT(weight_file_in, 0)));
  //Rprintf("weight_file: %s\n", weight_file); 

  PROTECT(dat_file_in = AS_CHARACTER(dat_file_in));
  char * dat_file;
  dat_file = R_alloc(strlen(CHAR(STRING_ELT(dat_file_in, 0))), sizeof(char));
  strcpy(dat_file, CHAR(STRING_ELT(dat_file_in, 0)));
  
  PROTECT(conf_file_in = AS_CHARACTER(conf_file_in));
  char * conf_file;
  conf_file = R_alloc(strlen(CHAR(STRING_ELT(conf_file_in, 0))), sizeof(char));
  strcpy(conf_file, CHAR(STRING_ELT(conf_file_in, 0)));

  PROTECT(input_file_in = AS_CHARACTER(input_file_in));
  char * input_file;
  input_file = R_alloc(strlen(CHAR(STRING_ELT(input_file_in, 0))), sizeof(char));
  strcpy(input_file, CHAR(STRING_ELT(input_file_in, 0)));

  PROTECT(output_file_in = AS_CHARACTER(output_file_in));
  char * output_file;
  output_file = R_alloc(strlen(CHAR(STRING_ELT(output_file_in, 0))), sizeof(char));
  strcpy(output_file, CHAR(STRING_ELT(output_file_in, 0)));

  PROTECT(thresh_in = AS_NUMERIC(thresh_in));
  double *xT;
  xT = NUMERIC_POINTER(thresh_in);
  float thresh = (float) * xT;

  float hier_thresh = 0.5;
  int display = 0;
  test_detector(dat_file, conf_file, weight_file, input_file, 
                thresh, hier_thresh, output_file, display);
  UNPROTECT(6);
  return thresh_in;
}


