genesis: main.cpp
	c++ `Magick++-config --cxxflags --cppflags` -O2 -o genesis main.cpp   `Magick++-config --ldflags --libs`