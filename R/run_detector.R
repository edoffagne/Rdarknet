
run_detector = function(thresh=0.3, weight_file)
{ x = .Call("r_run_detector", thresh, weight_file)
  return(x)
}

