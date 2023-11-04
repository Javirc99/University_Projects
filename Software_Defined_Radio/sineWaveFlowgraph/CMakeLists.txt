# GNU Radio C++ Flow Graph CMakeLists.txt
#
# Title: Your First Flowgraph
# GNU Radio version: 3.10.7.0


cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)

project(sineWaveFlowgraph)

find_package(Gnuradio "3.10" COMPONENTS
    blocks
    fec
    fft
    filter
    analog
    digital
    dtv
    audio
    channels
    pdu
    iio
    qtgui
    trellis
    uhd
    uhd UHD 4.0 RFNoC
    video-sdl
    vocoder
    wavelet
    zeromq
    network
    soapy
)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC TRUE)



add_executable(sineWaveFlowgraph sineWaveFlowgraph.cpp)
target_link_libraries(sineWaveFlowgraph
    gnuradio::gnuradio-blocks
    gnuradio::gnuradio-qtgui
    gnuradio::gnuradio-analog
    gnuradio::gnuradio-qtgui
)

