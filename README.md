# capture
captures from microphone and scrolls a timegraph over your terminal.

requires fftw3


# some background info

mysound seems to have been inspired byt this tuto:
[200~https://equalarea.com/paul/alsa-audio.html

# usage 

record uses the default device.
What is it?
The keyword "default" will access the default subdevice on the default soundcard, which will probably be hw:0,0 for a typical single Sound Blaster sound card. Now with the "PCM hw type" you are able to define aliases for your devices. 
From: https://alsa.opensrc.org/Asoundrc

# build

use clang compiler to build.

Test your microphone

arecord --device="hw:0,0" -vv -f dat /dev/null

Get your device and card :

arecord -l
arecord -l
**** List of CAPTURE Hardware Devices ****
card 0: PCH [HDA Intel PCH], device 0: 92HD95 Analog [92HD95 Analog]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

card 0, device 0 -> hw:0,0

arecord -d 10 -c 1 -f S24_LE -t wav test.wav
aplay test.wav

links about using alsa
to sort
also setup the computer's for audio, test in audio settings

https://unix.stackexchange.com/questions/192554/issues-with-arecord-command-channels-count-non-available
https://bbs.archlinux.org/viewtopic.php?id=278288
https://linuxconfig.org/how-to-test-microphone-with-audio-linux-sound-architecture-alsa
https://bbs.archlinux.org/viewtopic.php?id=196525

watchuseek
https://www.watchuseek.com/threads/open-source-timing-software.2542874/page-16?nested_view=1&sortby=oldest#replies
https://www.watchuseek.com/threads/how-i-measure-accuracy-and-precision.5428770/?nested_view=1&sortby=oldest
https://www.watchuseek.com/threads/open-source-timing-software.2542874/page-14?post_id=56152420&nested_view=1&sortby=oldest#post-56152420
https://www.watchuseek.com/threads/open-source-timing-software.2542874/page-15?nested_view=1&sortby=oldest#replies

# connecting the olympus LS100

on the adder (system76)
turn on the ls100
connect the usb to the nb
connect to the ls100
remote(composite) will appear on the ls100
a drive is mounted
Then the LS100 appears in the sound settings, as well as when running arecord.

$ arecord -l
**** List of CAPTURE Hardware Devices ****
card 0: PCH [HDA Intel PCH], device 0: ALC245 Analog [ALC245 Analog]
  Subdevices: 0/1
  Subdevice #0: subdevice #0
card 1: RECORDER [DIGITAL VOICE RECORDER], device 0: USB Audio [USB Audio]
  Subdevices: 0/1
  Subdevice #0: subdevice #0

arecord --device="hw:1,0" -vv -f dat /dev/null

Recording WAVE '/dev/null' : Signed 16 bit Little Endian, Rate 48000 Hz, Stereo
Warning: rate is not accurate (requested = 48000Hz, got = 44100Hz)
         please, try the plug plugin 
Hardware PCM card 1 'DIGITAL VOICE RECORDER' device 0 subdevice 0
Its setup is:
  stream       : CAPTURE
  access       : RW_INTERLEAVED
  format       : S16_LE
  subformat    : STD
  channels     : 2
  rate         : 44100
  exact rate   : 44100 (44100/1)
  msbits       : 16
  buffer_size  : 22050
  period_size  : 5513
  period_time  : 125011
  tstamp_mode  : NONE
  tstamp_type  : MONOTONIC
  period_step  : 1
  avail_min    : 5513
  period_event : 0
  start_threshold  : 1
  stop_threshold   : 22050
  silence_threshold: 0
  silence_size : 0
  boundary     : 6206523236469964800
  appl_ptr     : 0
  hw_ptr       : 0

 arecord --device="hw:1,0" -d 5 -c 1 -f S16_LE -t wav test.wav
Recording WAVE 'test.wav' : Signed 16 bit Little Endian, Rate 8000 Hz, Mono
arecord: set_params:1358: Channels count non available
 gonze:tico/ (dev) $ arecord --device="hw:1,0" -d 5 -f S16_LE -t wav test.wav
Recording WAVE 'test.wav' : Signed 16 bit Little Endian, Rate 8000 Hz, Mono
arecord: set_params:1358: Channels count non available
 gonze:tico/ (dev) $ arecord --device="hw:1,0" -d 5 -c 2 -f S16_LE -t wav test.wav
Recording WAVE 'test.wav' : Signed 16 bit Little Endian, Rate 8000 Hz, Stereo
Warning: rate is not accurate (requested = 8000Hz, got = 44100Hz)
         please, try the plug plugin 

Seems need to have only a mono input source
LS100 only outputs stereo
Make mono from stereo:
https://superuser.com/questions/1176632/create-alsa-device-with-1-channel-from-2


