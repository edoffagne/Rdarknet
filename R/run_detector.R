
run_detector = function(z=1)
{ x = .Call("r_run_detector", c(z))
  return(x)
}

