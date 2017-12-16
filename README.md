

# Rdarknet

[![Build Status](https://travis-ci.org/edoffagne/Rdarknet.svg?branch=master)](https://travis-ci.org/edoffagne/Rdarknet)

## Introduction

[Darknet](http://pjreddie.com/darknet) is an open source neural network framework
written in C and CUDA. This package only exposes a function to run a detector
on a pre-trained model. 

## Usage

Type the following lines in an R session:

 ```shell
 require(Rdarknet)
 run_detector(0.3, "cfg/yolo.weights", "cfg/coco.dat", "cfg/yolo.cfg",
              "data/dog.jpg", "out.jpg")
 ```

Please note the weights are not included in the package and need to be downloaded
[here](https://pjreddie.com/media/files/yolo.weights).

## Installation 

To install the package, run the following command in a terminal:

```shell
$ R -e "devtools::install_github('edoffagne/Rdarknet')"
 ```



