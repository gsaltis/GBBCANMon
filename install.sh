#!/bin/bash
if [ "" == "$1" ];
then
  mode=gbb
elif [ "GBB" == $1 ] || [ "gbb" == $1 ];
then
  mode=gbb
elif [ "ESNA" == $1 ] || [ "esna" == $1 ];
then
  mode=esna
else
  echo unknown mode $1
  exit -1
fi
rcfile=canmon-$mode.rc
echo $rcfile
cp $rcfile /etc/init.d/canmon
ln -s /etc/init.d/canmon /etc/rc1.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc2.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc3.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc4.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc5.d/K99canmon
ln -s /etc/init.d/canmon /etc/rc6.d/K99canmon
echo Installing canmon in $mode mode
timedatectl set-ntp false
