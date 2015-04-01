#include "player.hh"

media_player::media_player(){
	ao_initialize();
	driver = ao_default_driver_id();
	mpg123_init();
	mh = mpg123_new(NULL, &err);
	buffer_size = mpg123_outblock(mh);
	buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));
}

void media_player::play(std::string filename){
	mpg123_open(mh, filename.c_str());
	mpg123_getformat(mh, &rate, &channels, &encoding);
	
	format.bits = mpg123_encsize(encoding) * 8;
	format.rate = rate;
	format.channels = channels;
	format.byte_format = AO_FMT_NATIVE;
	format.matrix = 0;
	dev = ao_open_live(driver, &format, NULL);
	
	while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
        	ao_play(dev, buffer, done);
}
