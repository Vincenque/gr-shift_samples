# gr-shift_samples
Simple GNU Radio block to shift samples. 
If samples are pushed out from buffer, they are going to the start of buffer.

Tested on GNU Radio Companion 3.10.7.0 (Python 3.10.12).

To build and test:
```
mkdir build 
cd build 
cmake .. 
make -j4 
sudo make install 
sudo ldconfig
gnuradio-companion ../examples/testShiftSamples.grc
```


To rebuild (in build folder) and test:
```
sudo make uninstall
cd ..
sudo rm -r build
mkdir build 
cd build 
cmake .. 
make -j4 
sudo make install 
sudo ldconfig
gnuradio-companion ../examples/testShiftSamples.grc
```
