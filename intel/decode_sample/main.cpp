#include <iostream>
#include <string>
#include <decode.hpp>


int main(int argc, char** argv)
{
	std::string videoname = "/home/hddl/hddl/hddl-samples/barrier_demo/video/barrier_1080x720.h264";
	if (argc > 1) {
		videoname = argv[1];
	}

	std::string devType = "hw"; 	//default hw, or sw;

	mfxU32 codecFormat = MFX_CODEC_AVC; // MFX_CODEC_HEVC;(h265)
        

	return 0;
}