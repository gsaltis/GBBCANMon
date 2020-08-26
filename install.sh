#!/bin/sh
cp canmon.rc /etc/init.d/canmon
ln -s /etc/init.d/canmon /etc/rc1.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc2.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc3.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc4.d/S99canmon
ln -s /etc/init.d/canmon /etc/rc5.d/K99canmon
ln -s /etc/init.d/canmon /etc/rc6.d/K99canmon
