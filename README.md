## About

A console application that allows you to apply various filters to images, similar to filters in popular graphic editors.
Input and output image files must be in 24-bit BMP format without compression and without a color table. 

## Format of command line arguments

`{program name} {input file path} {output file path}
[-{filter name 1} [filter parameter 1] [filter parameter 2] ...]
[-{filter name 2} [filter parameter 1] [filter parameter 2] ...] ...`

### List of basic filters

#### Crop (-crop width height)

#### Grayscale (-gs)

#### Negative (-neg)

#### Sharpening (-sharp)

#### Edge Detection (-edge threshold)

#### Gaussian Blur (-blur sigma)

### My Filter (-mf)


The code was written 20.03.22