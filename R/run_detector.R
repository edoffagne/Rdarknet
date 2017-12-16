
#' Run Detector
#'
#' Runs object detection on image file using a pre-trained model.  
#'
#' @usage run_detector(0.3, "cfg/yolo.weights", "cfg/coco.dat", "cfg/yolo.cfg",
#'                    "data/dog.jpg", "out.jpg")
#'
#' @param thresh Threshold to use
#' @param weight_file File with the weights
#' @param dat_file Dat file
#' @param conf_file Configuration file
#' @param input_file Input image file
#' @param output_file Output image file
#' @rdname run_detector
#' @export
#' @useDynLib libdarknet 

run_detector = function(thresh=0.3, weight_file, dat_file, conf_file,
                                    input_file, output_file)
{ x = .Call("r_run_detector", thresh, weight_file, dat_file, conf_file,
                              input_file, output_file)
  return(x)
}

