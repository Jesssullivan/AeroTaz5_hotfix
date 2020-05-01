## *Taz 5 Aerostruder thermistor hotfix*

Quickly patched 2016 Q2 "Uaru" firmware for Lulz Taz 5 + Aerostruder to use a standard 100k EPCOS thermistor instead of the sheathed Semitec provided by E3D.   

This Lulzbot Marlin source is more than 4 years old, these patches just get the machine running again ASAP.

upload to the printer with ```arduino --upload Marlin/*.ino```  


#### *Changes:*

- Replace struct conflict in ```stdio.h``` with Marlin SD reader files at ```/hardware/tools/avr/avr/include/stdio.h```
  - *This was later fixed with [this Marlin PR](https://github.com/MarlinFirmware/Marlin/pull/5114/commits/8906c93ce54be7a40aff2259c62154337e15c332)*

- Change ```u8g.h``` locations in ```dogm_font_data_marlin.h```
