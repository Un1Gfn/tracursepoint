https://github.com/Un1Gfn/tracursepoint

Trackpoint
https://askubuntu.com/questions/37824/what-is-the-best-way-to-configure-a-thinkpads-trackpoint/553926
https://wiki.archlinux.org/index.php/TrackPoint#GUI_configuration
http://thinkwiki.org/wiki/How_to_configure_the_TrackPoint#Graphical_Frontends
https://aur.archlinux.org/packages/gpointing-device-settings/
http://tpctl.sourceforge.net/configure-trackpoint.html

CDK
https://en.wikipedia.org/wiki/CDK_(programming_library)
https://aur.archlinux.org/packages/libcdk/
https://invisible-island.net/cdk/manpage/cdk_slider.3.html

ncurses official site
https://invisible-island.net/ncurses/
https://www.gnu.org/software/ncurses/

Video
53593 2011 thecplusplusguy https://www.youtube.com/watch?v=Cg_u60jX8Y4&list=PL2C01CC54638DD952
58418 2014 Giga Raptor https://www.youtube.com/channel/UCWM9F4d53xWCNcpixy9WIBA/search?query=NCurses+Tutorial
25804 2016 Casual Coder https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v

Long tutor
https://www.gnu.org/software/ncurses/ncurses-intro.html

Long tutor w/ cdk
http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/

Reference manual
/usr/share/man/
https://invisible-island.net/ncurses/man/

key=stdscr
for i in $(pacman -Qql ncurses|grep man); do
  zgrep $key $i &>/dev/null
  if [ $? -eq 0 ]; then
    echo $i
  fi
done
