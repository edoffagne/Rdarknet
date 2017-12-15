
run_detector = function(thresh=0.3, weight_file, dat_file, conf_file,
                                    input_file, output_file)
{ x = .Call("r_run_detector", thresh, weight_file, dat_file, conf_file,
                              input_file, output_file)
  return(x)
}

