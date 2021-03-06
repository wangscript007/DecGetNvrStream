#ifndef __LIB_AUDIO_H
#define __LIB_AUDIO_H

#include "lib_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HI3531
#define TL_AUDIO_CH_TALK_BACK	36//16
#define TL_AUDIO_CH_PLAY_BACK	37//32
#else
#define TL_AUDIO_CH_TALK_BACK	16//16
#define TL_AUDIO_CH_PLAY_BACK	17//32
#endif

#define TL_AUDIO_MAX_BUF		(4*480*2)

typedef struct{
	int channel;
	unsigned char *data;
	unsigned int len;
	unsigned long long time_stamp;
	int is_raw_data;
}audio_frame_t;

typedef struct{
	int min_val;
	int max_val;
}audio_volume_atr_t;

typedef int (*AudioStreamCB)(audio_frame_t *stream);
int tl_audio_set_cb(AudioStreamCB pAudioStreamCB);

int tl_audio_open(void);
int tl_audio_read_data(unsigned char *in_buf, unsigned int in_buf_len, audio_frame_t *out_frame, unsigned int timeout_us);
int tl_audio_write_data(audio_frame_t *in_frame);
int tl_audio_close(void);

int tl_audio_enable(int channel);
int tl_audio_disable(int channel);

int tl_audio_out_sel(int channel);
int tl_audio_get_volume_atr(audio_volume_atr_t *patr);
int tl_audio_set_volume(int val);

#ifdef __cplusplus
}
#endif

#endif

