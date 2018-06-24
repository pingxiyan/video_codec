# Video_Codec
Test all video decode, encode and transcode.

# Nivida Graphic acceleration.
Refer: [Nvidia FFmepg](https://developer.nvidia.com/ffmpeg)

# Nividia cuda and drive install guide 
Refer: https://blog.csdn.net/sikao_luwei/article/details/69375126

# Test Steps
  1. Dependency:  <br>
     FFmpeg: https://git.ffmpeg.org/ffmpeg.git<br>

    $ wget http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz
    $ tar -xf yasm-1.3.0.tar.gz
    $ cd yasm-1.3.0
    $ ./configure
    $ make -j8
    $ sudo make install

    $ git clone https://git.videolan.org/git/ffmpeg/nv-codec-headers.git
    $ make
    $ sudo make install
    $ export PKG_CONFIG_PATH=/home/hddl/yxp/nv-codec-headers
    
    Why include "nv-codec-headers"? 
    Refer: https://superuser.com/questions/1299064/error-cuvid-requested-but-not-all-dependencies-are-satisfied-cuda-ffnvcodec
    
   2. Compile FFmpeg: <br>
   
    $ git clone https://git.ffmpeg.org/ffmpeg.git
    $ cd ffmpeg
    $ ./configure --enable-cuda --enable-cuvid --enable-nvenc --enable-nonfree --enable-libnpp --extra-cflags=-I/usr/local/cuda/include --extra-ldflags=-L/usr/local/cuda/lib64
    $ make -j8
    
    Here you will see:
    -rwxrwxr-x  1 hddl hddl  18922424 6月  24 15:49 ffmpeg*
    -rwxrwxr-x  1 hddl hddl 100611816 6月  24 15:49 ffmpeg_g*
    -rwxrwxr-x  1 hddl hddl  18828184 6月  24 15:49 ffprobe*
    -rwxrwxr-x  1 hddl hddl 100205176 6月  24 15:49 ffprobe_g*
    
  3. test transcoding
  
    TEST_VIDEO=~/zizhu_parking_2017-09-23_partz_demo_1600x1200_mask.264
    $ ./ffmpeg -y -hwaccel cuvid -c:v h264_cuvid -vsync 0 -i $TEST_VIDEO -vf scale_npp=800:600 -vcodec h264_nvenc result800_600.mp4
    $ ./ffmpeg -y -hwaccel cuvid -c:v h264_cuvid -vsync 0 -i $TEST_VIDEO -vf scale_npp=800:600 -vcodec h264_nvenc -maxrate 100k result800_600_maxrate_100k.mp4
    $ ./ffmpeg -y -hwaccel cuvid -c:v h264_cuvid -vsync 0 -i $TEST_VIDEO -vf scale_npp=800:600 -vcodec h264_nvenc -maxrate 200k result800_600_maxrate_200k.mp4
    $ ./ffmpeg -y -hwaccel cuvid -c:v h264_cuvid -vsync 0 -i $TEST_VIDEO -vf scale_npp=800:600 -vcodec h264_nvenc -maxrate 300k result800_600_maxrate_300k.mp4
    
    -rw-rw-r--  1 hddl hddl    902430 6月  24 16:27 result800_600_maxrate_100k.mp4
    -rw-rw-r--  1 hddl hddl   1853611 6月  24 16:28 result800_600_maxrate_200k.mp4
    -rw-rw-r--  1 hddl hddl   2756551 6月  24 16:28 result800_600_maxrate_300k.mp4
    -rw-rw-r--  1 hddl hddl  19597721 6月  24 16:14 result800_600.mp4

    
