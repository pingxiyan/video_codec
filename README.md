# Video_Codec
Test all video decode, encode and transcode.

# Nivida Graphic acceleration.
Refer: [Nvidia FFmepg](https://developer.nvidia.com/ffmpeg)

#### Steps (Based on CentOS 7.4)
  1. Dependency:  <br>
     FFmpeg: https://git.ffmpeg.org/ffmpeg.git<br>
     Libav: https://github.com/libav/libav<br>

    $ sudo yum group install Development tools
    $ wget http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz
    $ tar -xf yasm-1.3.0.tar.gz
    $ cd yasm-1.3.0
    $ ./configure
    $ make -j8
    $ sudo make install

    Compile FFmpeg:
    $ ./configure
    $ make -j8
    
    Compile libav:
    $ ./configure
    $ make -j8
    
    
