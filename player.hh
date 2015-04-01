#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include <ao/ao.h>
#include <mpg123.h>

class media_player{
private:
	mpg123_handle *mh;
	unsigned char *buffer;
    	size_t buffer_size;
    	size_t done;
    	int err;

    	int driver;
    	ao_device *dev;

    	ao_sample_format format;
    	int channels, encoding;
    	long rate;
	
public:
	media_player();
	void play(std::string filename);
};

#endif
