# capture
captures from microphone and scrolls a timegraph over your terminal.

requires fftw3


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

