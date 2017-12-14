#include "darknet.h"

void test_detector(char *datacfg, char *cfgfile, char *weightfile, char *filename, float thresh, float hier_thresh, char *outfile, int fullscreen);

void train_detector(char *datacfg, char *cfgfile, char *weightfile, int *gpus, int ngpus, int clear);

