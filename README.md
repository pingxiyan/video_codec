# Video_Codec
Test all video decode, encode and transcode.

# Nivida Graphic acceleration.
Refer: [Nvidia FFmepg](https://developer.nvidia.com/ffmpeg)

# Nividia cuda and drive install guide 
Refer: https://blog.csdn.net/xierhacker/article/details/53035989

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
    $ ./configure --enable-cuda --enable-cuvid --enable-nvenc --enable-nonfree --enable-libnpp --extra-cflags=-usr/local/cuda/include --extra-ldflags=-L/usr/local/cuda/lib64
    $ make -j8
    
    Compile libav:
    $ ./configure
    $ make -j8
    
    
