# Patternizer 

Library for analysis of stock prices and looking for repetitive patterns

## Installation

1. Download this project
git clone https://github.com/grishan/kalich.git

2. Download rapidjson, library to parse data in json format
git clone https://github.com/miloyip/rapidjson.git

3. Install curl

If you are on ubuntu, 

	sudo apt-get install curl
	sudo apt-get install libcurl4-openssl-dev

## Installation

Test program downloads from quandl quotes of apple (as a vector of doubles) and dump them into the file which you can plot in gnuplot:

	set xdata time
	set timefmt "%Y-%m-%d"
	p 'AAPL' u 1:2 w l
